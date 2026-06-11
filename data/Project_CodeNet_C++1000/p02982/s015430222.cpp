#include <iostream>
#include <iomanip>
/*cout<<setprecision(5)<<ret<<endl;で、数字部分を計5桁表示かつゼロ埋め無*/
/*cout<<fixed<<setprecision(5)<<ret<<endlで、小数部のみ5桁表示かつゼロ埋め有*/
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

/* [Shift+Command+b]（コンパイル）ー＞[Ctrl+Shift+^]（ターミナル起動）ー＞[./a.out] */


//////////////////
//  A
/*int main(void){
    int n,a,b;cin>>n>>a>>b;
    int ret=(b>n*a)? n*a : b;
    cout<<ret<<endl;
    return 0;
}*/
//////////////////
//  B
int main(void){
    int n,d;cin>>n>>d;
    vector<vector<int>> map(n,vector<int>(d));
    rep(i,n){
        rep(j,d){
            cin>>map[i][j];
        }
    }
    
    int ret=0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            //距離求める
            ll dis=0LL;
            rep(x,d){
                dis+=pow((map[i][x]-map[j][x]),2);
            }
            //整数かCheck
            for(ll y=0LL; y<=dis; y++){
                if(pow(y,2)==dis){
                    ret++;
                    break;
                }
            }
        }
    }
    cout<<ret<<endl;

    return 0;
}
//////////////////
//  C
/*int main(void){

    return 0;
}*/
//////////////////
//  D
/*int main(void){

    return 0;
}*/
