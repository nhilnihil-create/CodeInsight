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
    ll n, p;
    string s;
    cin >> n >> p >> s;
    ll ans = 0, cnt = 0;
    vector<ll> a(n);
    if(p == 2 || p == 5){
        rep(i, n){
            cnt = cnt * 10;
            cnt += s[i]-'0';
            cnt %= p;
            a[i] = cnt;
        }
        rep(i, n){
            if(a[i] == 0)ans += i+1;
        }
        cout << ans << endl;
    }
    else{
        ll t = 1;
        for(int i = n-1; i >= 0; i--){
            cnt += t * (s[i]-'0') % p;
            cnt %= p;
            a[i] = cnt;
            t = t * 10 % p;
        }
        map<ll, ll> mp;
        mp[0]++;
        for(int i = n-1; i >= 0; i--){
            ans += mp[a[i]];
            mp[a[i]]++;
        }
        cout << ans << endl;
    }
}