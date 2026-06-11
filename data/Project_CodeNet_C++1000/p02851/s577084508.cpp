#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,k;
    cin >> n >> k;
    ve<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;
    ve<int> s(n+1);
    s[0] = 0;
    rep(i,n) s[i+1] = (s[i] + a[i]) % k;
    map<int,int> mp;
    queue<int> q;
    ll ans = 0;
    rep(j,n+1){
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        if(q.size() == k){
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
