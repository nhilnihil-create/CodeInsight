#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 100000007;

int main() {
    ll N;cin >> N;
    map<ll,int> mp;
    ll ans = 0;
    for (int i = 0;i < N;i++){
        ll A;cin >> A;
        ans += mp[i - A];
        mp[A + i]++;
    }
    cout << ans << endl;
}
