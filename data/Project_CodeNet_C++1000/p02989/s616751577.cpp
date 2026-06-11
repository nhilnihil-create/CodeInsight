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
    string a;cin>>a;
    sort(a.begin(),a.end());
    if(a[0]==a[1] && a[2]==a[3] && a[0]!=a[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}*/
//////////////////
//  B
/*int main(void){
    int n;cin>>n;
    vector<int> p(n);
    rep(i,n){
        cin>>p[i];
    }
    int cnt=0;
    for(int i=1;i<n-1;i++){
        if((p[i-1]<p[i]&&p[i]<p[i+1])||(p[i-1]>p[i]&&p[i]>p[i+1])){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}*/
//////////////////
//  C
int main(void){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int low=a[n/2-1],high=a[n/2];
    cout<<high-low<<endl;
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
