#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    int tot = 0;
    rep(i,h){
        cin >> s.at(i);
        
    }
    int ans = 0;
    rep(i,1<<h){
        rep(j,1<<w){
            int cnt = 0;
            rep(ii,h){
                rep(jj,w){
                    if(i>>ii&1) continue;
                    if(j>>jj&1) continue;
                    if(s.at(ii).at(jj) == '#') cnt++;
                }
            }
            if(cnt == k) ans++;

        }
    }
    cout << ans << endl;
}