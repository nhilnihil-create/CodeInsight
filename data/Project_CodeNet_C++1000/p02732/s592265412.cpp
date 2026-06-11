#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (2147483647)
#define MOD (int)(1e9 + 7) 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<ll> ball(n+5, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        ball[arr[i]]++;
    }
    vector<ll> pre(n+5, 0);
    ll res = 0;
    for(int i = 0; i <= n; ++i) {
        pre[i] = ball[i] * (ball[i] - 1) / 2;
        res += pre[i];
    }
    for(int i = 0; i < n; ++i) {
        cout << res - pre[arr[i]] + ((ball[arr[i]] - 1) * (ball[arr[i]] - 2) / 2) << '\n';
    }
    return 0;
}