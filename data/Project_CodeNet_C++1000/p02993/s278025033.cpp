#include <iostream>
#include <iomanip>
/*cout<<setprecision(11)<<ret<<endl;で、数字部分を計11桁表示かつゼロ埋め無*/
/*cout<<fixed<<setprecision(11)<<ret<<endlで、小数部のみ11桁表示かつゼロ埋め有*/
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//Shift+Command+bでデバッグ
//その後ターミナルで./a.outを実行
//入力を貼り付ける

//////////////////
//  A
int main(void){
    int x;cin>>x;
    int a=-1;
    rep(i,4){
        int tmp=x%10;
        if(a==tmp){
            cout<<"Bad"<<endl;
            return 0;
        }else{
            a=tmp;
            x/=10;
        }
    }
    cout<<"Good"<<endl;

    return 0;
}
//////////////////
//  B
/*int main(void){
    int n,x;cin>>n>>x;
    int sum=0,cnt=1;

    rep(i,n){
        int l;cin>>l;
        sum+=l;
        if(sum>x){
            break;
        }else{
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}*/
//////////////////
//  C
/*int main(void){
    double w,h,x,y;cin>>w>>h>>x>>y;
    bool ret=(2*x==w)&&(2*y==h);
    cout<<(double)((w*h)/2.0)<<" "<<ret<<endl;
    return 0;
}*/
//////////////////
//  D　いけそう感がある。しゃくとり法
/*int main(void){

    return 0;
}*/
//////////////////
//  E
/*int main(void){

    return 0;
}*/
//////////////////
//  F
/*int main(void){

    return 0;
}*/
