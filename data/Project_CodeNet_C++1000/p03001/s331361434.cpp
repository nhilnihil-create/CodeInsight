#include <iostream>
#include <iomanip>
/*cout <<setprecision(11)<<ret<<endl;で、数字部分を計11桁表示*/
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
/*int main(void){
    int x,a;cin>>x>>a;
    if(x<a) cout<<"0"<<endl;
    else cout<<"10"<<endl;
    return 0;
}*/
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
int main(void){
    double w,h,x,y;cin>>w>>h>>x>>y;
    bool ret=(2*x==w)&&(2*y==h);
    cout<<(double)((w*h)/2.0)<<" "<<ret<<endl;
    return 0;
}
//////////////////
//  D
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
