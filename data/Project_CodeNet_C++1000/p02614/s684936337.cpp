/*
      author : Nishikawa
      created: 05.08.2020 15:00:14
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int H,W,K;
    cin >> H >> W >> K;
    vector<vector<char> > vv(H,vector<char>(W));
    vector<vector<char> > vv_tmp(H,vector<char>(W));
    rep(i,H)rep(j,W) cin >> vv[i][j];
//    rep(i,H){rep(j,W){ cout << vv[i][j];} cout << endl;}

    int tot=0;
    int _H=1,_W=1;
    for(int i=0; i<H; i++){
        _H*=2;
    }
    for(int i=0; i<W; i++){
        _W*=2;
    }

    for(int i=0; i<_H; i++){
        for(int j=0; j<_W; j++){
            rep(i,H)rep(j,W) vv_tmp[i][j]=vv[i][j];
            for(int k=0; k<H; k++){
                if(i>>k & 1){
                    for(int l=0; l<W; l++){
                        vv_tmp[k][l]='r';
                    }
                }
            }
            for(int k=0; k<W; k++){
                if(j>>k & 1){
                    for(int l=0; l<H; l++){
                        vv_tmp[l][k]='r';
                    }
                }
            }
            int count=0;
            for(int k=0; k<H; k++){
                for(int l=0; l<W; l++){
                    if(vv_tmp[k][l]=='#') count++;
                }
            }
            if(count==K) {
                tot++;
                /*rep(i,H){rep(j,W){ 
                    cout << vv_tmp[i][j];
                } 
                cout << endl;}*/
            }
        }
    }
    cout << tot << endl;
    
    return 0;
}