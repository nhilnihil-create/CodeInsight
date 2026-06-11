#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> C.at(i).at(j);
    int ans=0;
    rep(i,(1<<H)) {
        rep(j,(1<<W)) {
            int B=0;
            rep(k,H) {
                rep(l,W) {
                    if((i>>k)&0==0 && (j>>l)&0==0 && C.at(k).at(l)=='#') B++;
                }
            }
            if(B==K) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}