#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n), s(n), b(n);
    rep(i, n)cin >> a[i];
    rep(i, n){
        if(!i)s[i] = a[i];
        else s[i] = s[i-1] + a[i];
    }
    rep(i, n){
        b[i] = s[i]-i-1;
        if(b[i] < 0)b[i] = k - (-b[i] % k);
        b[i] %= k;
    }
    map<ll, ll> mp;
    mp[0]++;
    rep(i, n){
        if(i == k-1)mp[0]--;
        else if(i >= k)mp[b[i-k]]--;
        ans += mp[b[i]];
        mp[b[i]]++;
    }
    cout << ans << endl;
}
