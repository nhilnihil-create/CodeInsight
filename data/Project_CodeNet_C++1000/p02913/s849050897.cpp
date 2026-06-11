#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
template <typename T> bool chmax(T &a, const T b){if(a < b){a = b;return true;}return false;}
template <typename T> bool chmin(T &a, const T b){if(a > b){a = b;return true;}return false;}
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(i = n-1;i >= 0;--i){
        for(j = n-1;j > i;--j){
            if(s.at(i) == s.at(j)) chmax(dp.at(i).at(j), dp.at(i+1).at(j+1)+1);
            chmax(ans, min(dp.at(i).at(j), j-i));
        }
    }
    cout << ans << endl;
    return 0;
}