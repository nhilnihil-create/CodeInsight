#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    int h,w,k,ans=0;
    cin >> h >> w >> k;
    char mp[h][w];
    rep(i,h)rep(j,w) cin >> mp[i][j];
    rep(i,1<<h){
        bitset<6> s(i);
        rep(j,1<<w){
            int cnt = 0;
            bitset<6> t(j);
            rep(k,h)rep(l,w){
                if(s.test(k)||t.test(l)) continue;
                else if(mp[k][l]=='#') cnt++;
            }
            if(cnt==k) ans++;
        }
    }
    cout << ans << endl;
}