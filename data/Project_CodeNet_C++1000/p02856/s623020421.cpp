#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define FOR(n) for (int _i = 0; _i < (n); _i++)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
    int n; cin >> n;
    ll ans = -1;
    ll count = 0;
    rep(i,n){
        ll a, b; cin >> a >> b;
        ans += b;
        count += a*b;
    }
    ans += (count-1)/9;
    cout << ans << endl;
}