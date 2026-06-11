#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s;
    rep(i,h)rep(j,w){
        string t;
        cin >> t;
        s.push_back(t);
    }
    int ans = 0;
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            vector<string> ss = s;
            for(int ii=0; ii<h; ii++){
                if(i>>ii & 1){
                    rep(k,w) ss[ii][k]='r';
                }
            }
            for(int ii=0; ii<w; ii++){
                if(j>>ii & 1){
                    rep(k,h) ss[k][ii]='r';
                }
            }

            int now = 0;
            rep(ii,h)rep(jj,w){
                if(ss[ii][jj]=='#') now++;
            }
            if(now == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}