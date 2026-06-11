#include <bits/stdc++.h>
/*cout<<setprecision(5)<<ret<<endl;で、数字部分を計5桁表示かつゼロ埋め無*/
/*cout<<fixed<<setprecision(5)<<ret<<endlで、小数部のみ5桁表示かつゼロ埋め有*/
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
/* [Shift+Command+b]（コンパイル）ー＞[Ctrl+Shift+`]（ターミナル起動）ー＞[./a.out] */

//////////////////
//  A
/*int main(void){
    int a,b,c;cin>>a>>b>>c;
    int d=a-b;
    if(d>c){
        cout<<"0"<<endl;
    }else{
        cout<<c-d<<endl;
    }
    return 0;
}*/
//////////////////
//  B
int main(void){
    int n;cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(to_string(i).length()%2==1)cnt++;
    }
    cout<<cnt<<endl;
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
