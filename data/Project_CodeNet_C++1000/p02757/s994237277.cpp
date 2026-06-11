#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(10%p == 0){
        ll ans = 0;
        rep(r,n){
            if((s[r] - '0') % p == 0){
                ans += r + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    vector<int> d(n+1, 0);
    int ten = 1;
    for(int i = n-1; i >= 0; --i){
        int a = (s[i] - '0') * ten % p;
        d[i] = (d[i+1] + a) % p;
        ten *= 10;
        ten %= p;
    }
    vector<int> cnt(p);
    ll ans = 0;
    for(int i = n; i >= 0; --i){
        ans += cnt[d[i]]++;
    }
    cout << ans << endl;
    return 0;
}
