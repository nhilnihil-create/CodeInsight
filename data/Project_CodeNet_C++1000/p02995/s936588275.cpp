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
/*int main(void){
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
}*/
//////////////////
//  B
/*int main(void){
    int n,l;cin>>n>>l;
    int Left=l,Right=l+n-1;

    int eat;
    if(Left>=0)eat=Left;
    else if(0>=Right)eat=Right;
    else eat=0;

    int sum=n*(l-1) + n*(n+1)/2;//tigau

    cout<<(sum-eat)<<endl;
    return 0;
}*/
//////////////////
//  C //解説を見たら実装できた
long long gcd(long long a, long long b){//最大公倍数を求める
   if (a%b == 0){
       return(b);
   }else{
       return(gcd(b, a%b));
   }
}
long long lcm(long long a, long long b){//最小公倍数を求める
   return a * b / gcd(a, b);
}
int main(void){
    long long a,b,c,d;cin>>a>>b>>c>>d;

    long long l=lcm(c,d);//最小公倍数
    long long b_ret = b - b/c - b/d + b/l;//b以下の整数のうち、cでもdでもわれないものの個数
    a=a-1;
    long long a_ret = a - a/c - a/d + a/l;

    cout<<b_ret-a_ret<<endl;
    return 0;
}
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
