#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[10004];

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    int n,m;
    cin >> n >> m;
    ll sum = 0;
    for (int i=0;i<n;i++)
        cin >> arr[i], sum += arr[i];
    sort(arr, arr+n);
    ll cnt = 0;
    for (int i=n-1;i>=0;i--) {
        if (arr[i]*4*m >= sum)
            cnt++;
        else
            break;
        if (cnt == m) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
