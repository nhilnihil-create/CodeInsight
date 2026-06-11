#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli h, w;

int main(void){
    cin >> h >> w;
    vector<string> m(h);
    vector<vector<lli>> a(h, vector<lli>(w)), b(h, vector<lli>(w));
    rep(i, h) cin >> m[i];
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '#') continue;
            lli c = 0;
            int k;
            for(k = j; k < w && m[i][k] != '#'; k++){
                c++;
            }
            for(; j < k; j++) a[i][j] = c;
        }
    }
    rep(j, w){
        rep(i, h){
            if(m[i][j] == '#') continue;
            lli c = 0;
            int k;
            for(k = i; k < h && m[k][j] != '#'; k++){
                c++;
            }
            for(; i < k; i++) b[i][j] = c;
        }
    }
    lli ans = 0;
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '.') ans = max(ans, a[i][j]+b[i][j]-1);
        }
    }
    cout << ans << endl;
    return 0;
}
