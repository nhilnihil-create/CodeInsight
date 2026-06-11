#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    int ans = 0;
    rep(i,h) cin >> s[i];
    rep(i,1<<h){
        rep(j,1<<w){
            int cnt = 0;
            rep(x,h){
                rep(y,w){
                    if(i>>x & 1) continue;
                    if(j>>y & 1) continue;
                    if(s[x][y]  == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
