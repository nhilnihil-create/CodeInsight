#include "bits/stdc++.h"
using namespace std;

#define IOS     ios_base::sync_with_stdio(0)
#define int     long long

int32_t main() {
    IOS;
    int n;
    cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        cin >> arr2[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 3)
            break;
        if (arr1[i] == arr2[i]) {
            count++;
        }
        else {
            count = 0;
        }
    }
    if (count == 3) {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    delete[] arr1;
    delete[] arr2;
}