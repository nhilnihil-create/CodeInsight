#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for(int i=0; i<h; ++i){cin >> s[i];}

    int res = 0;
    for(int is=0; is<(1<<h); ++is){
        for(int js = 0; js<(1<<w); ++js){
            int cnt = 0;
            for(int i=0; i<h; ++i){
                for(int j=0; j<w; ++j){
                    if(is&(1<<i)){continue;}
                    if(js&(1<<j)){continue;}
                    if(s[i][j]=='#'){cnt++;}
                }
            }
            if(cnt==k){res++;}
        }
    }
    cout << res << endl;
}