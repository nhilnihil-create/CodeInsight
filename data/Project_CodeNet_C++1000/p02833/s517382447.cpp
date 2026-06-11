#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll k = 10;
    while(k<=n) {
        ans+=n/k;
        k*=5;
    }
    cout << ans << endl;
}
