#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int tate,yoko,k;
    cin >> tate >> yoko >> k;
    vector<vector<char>> table(tate,vector<char>(yoko));
    rep(i,tate){
        rep(j,yoko){
            cin >> table.at(i).at(j);
        }
    }
    int ans = 0;
    rep(i,1 << tate){
        bitset<6> V(i);
        rep(j,1 << yoko){
            bitset<6> H(j);
            int count = 0;
            rep(a,tate){
                rep(b,yoko){
                    if(V.test(a) && H.test(b)){
                        if(table.at(a).at(b) == '#') count++;
                    }
                }
            }
            if(count == k) ans++;
        }
    }
    cout << ans << endl;
}