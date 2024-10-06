#include <bits/stdc++.h>
using namespace std;

vector<int> unionArr(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else if (arr2[j] < arr1[i]) {
            if (unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        } else { // arr1[i] == arr2[j]
            if (unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    // Process remaining elements of arr1
    while (i < n) {
        if (unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    // Process remaining elements of arr2
    while (j < m) {
        if (unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main() {
    int n;
    cout << "Enter the size for the 1st array: ";
    cin >> n;
    vector<int> arr1(n);
    
    cout << "Enter elements for the 1st array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size for the 2nd array: ";
    cin >> m;
    vector<int> arr2(m);
    
    cout << "Enter elements for the 2nd array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = unionArr(arr1, arr2, n, m);

    cout << "Union of both arrays is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
