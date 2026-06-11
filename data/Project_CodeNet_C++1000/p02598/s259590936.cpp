#include <bits/stdc++.h>
using namespace std;

bool ok(int val, vector<int> arr, int k) {
    for(int i : arr) {
        k -= (i + val - 1) / val - 1;
    }
    return k >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int L = 1, R = 1e9 + 10;
    int mid = L + (R - L) / 2;
    while(L < R) {
        int mid = L + (R - L) / 2;
        if(ok(mid, arr, k)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L << endl;
}