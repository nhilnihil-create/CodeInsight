/**
*    author:  souzai32
*    created: 13.08.2020 13:57:44
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;
    bool x,y,z;
    int ans=0;

    rep(i,10){
        rep(j,10){
            rep(k,10){
                x=false; y=false; z=false;
                for(int l=0; l<s.size(); l++){
                    if(!x && s.at(l)-'0'==i) x=true;
                    else if(!y && x && s.at(l)-'0'==j) y=true;
                    else if(y && s.at(l)-'0'==k) z=true;
                }
                if(z){
                    ans++;
                    // cout << i << j << k << endl;
                }
                //  cout << i << j << k << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}