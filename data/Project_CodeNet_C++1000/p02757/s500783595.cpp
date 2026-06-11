#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n, p; cin >> n >> p;
    string s; cin >> s;

    if(p == 2 || p == 5){
        ll ans = 0;
        rep(i,n) if((s[i]-'0')%p == 0) ans += i+1;
        cout << ans << endl;
        return 0;
    }

    ll sum = 0, count = 1;
    map<ll,ll> mp; mp[0]++;
    rrep(i,n){
        sum += count * (s[i]-'0'); sum %= p;
        mp[sum]++;
        count *= 10; count %= p;
    }
    ll ans = 0;
    for(auto v : mp) ans += v.second*(v.second-1)/2;
    cout << ans << endl;
    return 0;
}