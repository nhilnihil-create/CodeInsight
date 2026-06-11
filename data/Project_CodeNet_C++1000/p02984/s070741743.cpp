#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    vector<int> mnt(n, 0);
    ll temp = 0;
    for (int i = 1; i < n - 1; i += 2) {
        temp += arr[i];
    }
    mnt[0] = s - 2*(temp);

    cout << mnt[0] << " ";
    for (int i = 1; i < n; i++) {
        mnt[i] = 2 * arr[i - 1] - mnt[i - 1];
        cout << mnt[i] << " ";
    }
    cout << endl;
}