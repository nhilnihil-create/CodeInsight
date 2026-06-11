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
    int a,b;cin>>a>>b;
    double c=(double)(a+b)/2.0;
    if(c==(a+b)/2) cout<<(int)c<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;
}*/
//////////////////
//  B
/*int main(void){
    int n;cin>>n;
    vector<int> v(n),w(n);
    rep(i,n){ cin>>v[i]; w[i]=v[i];}

    sort(v.begin(),v.end());
    int cnt=0;
    rep(i,n){
        if(v[i]!=w[i]){
            cnt++;
        }
    }
    if(cnt==0 || cnt==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}*/
//////////////////
//  C 
int main(void){
    ll n;cin>>n;
    vector<ll> a(n+1);
    rep(i,n+1)cin>>a[i];

    ll ret=0LL;
    rep(i,n){
        ll b;cin>>b;
        if(a[i]>=b){
            ret+=b;
        }else{
            ll tmp=a[i+1];
            a[i+1]-=b-a[i];
            if(a[i+1]>=0LL){
                ret+=b;
            }else{
                ret+=a[i]+tmp;
                a[i+1]=0LL;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
//////////////////
//  D
/*int main(void){

    return 0;
}*/
