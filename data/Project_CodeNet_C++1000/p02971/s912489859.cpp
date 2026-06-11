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
    int a;cin>>a;
    cout<<3*a*a<<endl;
    return 0;
}*/
//////////////////
//  B
/*int main(void){
    int n,d;cin>>n>>d;
    if(n%(2*d+1)==0){
        cout<<(n/(2*d+1))<<endl;
    }else{
        cout<<(n/(2*d+1))+1<<endl;
    }
    return 0;
}*/
//////////////////
//  C 
int main(void){
    int n;cin>>n;
    vector<int> v(n);
    vector<int> w(n);
    rep(i,n){
        cin>>v[i];
        w[i]=v[i];
    }

    sort(v.begin(),v.end(),greater<int>());

    int high,secondhigh;
    if(v[0]==v[1]) high=secondhigh=v[0];
    else{ 
        high=v[0];
        secondhigh=v[1];
    }

    rep(i,n){
        if(w[i]==high) cout<<secondhigh<<endl;
        else cout<<high<<endl;
    }
    return 0;
}
//////////////////
//  D
/*int main(void){

    return 0;
}*/
