#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int h,w,k;
    cin >>h>>w>>k;
    vector<string> C(h);
    rep(i, h){
            cin >> C[i];
    }
    int ans=0;
    rep(r, (1<<h)){
        rep(c, (1<<w)){
            int black = 0;
            rep(i, h){
                if((r & (1<<i)) != 0){
                        continue;
                    }
                rep(j, w){
                    if((c & (1<<j)) != 0){
                        continue;
                    }
                    if(C[i][j] == '#'){
                        black++;
                    }
                }
            }
            if(black==k) ans += 1;
        }
    }
    cout << ans << endl;
}