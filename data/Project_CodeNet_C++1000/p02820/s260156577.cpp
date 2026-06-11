#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k,r,s,p;
    string t;
    cin >> n >> k >> r>> s >> p >> t;
    int ans = 0;
    rep(i,n) {
        if(i-k >= 0) if(t[i] == t[i-k]){
            t[i] = '0';
        }
        if(t[i] == 'r')  {
            ans += p;
        }
        if(t[i] == 's') {
            ans += r;
        }
        if(t[i] == 'p') {
            ans += s;
        }
    }
    cout << ans << endl;
}
