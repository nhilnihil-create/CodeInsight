#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main() {
    int h, w, k; cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    int ans = 0;
    rep(i0, 1 << h){
        rep(j0, 1 << w){
            int count = 0;
            rep(i1, h){
                rep(j1, w){
                    if(i0 & 1<<i1) continue;
                    if(j0 & 1<<j1) continue;
                    if(c[i1][j1] == '#') ++count;
                }
            }if(count == k){++ans;}
        }
    }
    cout << ans << endl;
}

