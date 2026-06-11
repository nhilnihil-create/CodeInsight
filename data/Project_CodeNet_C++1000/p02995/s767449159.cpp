#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return(a%b)?gcd(b,a%b):b;}
ll lcm(ll a,ll b){return(a*b/gcd(a,b));}
const ll INF=1LL<<60;

ll a,b,c,d;

int main(){
    cin>>a>>b>>c>>d;
    ll cnt=b-a+1;;
    cnt-=b/c;
    cnt-=b/d;
    cnt+=(a-1)/c;
    cnt+=(a-1)/d;
    ll num=lcm(c,d);
    cnt+=(b/num);  
    cnt-=(a-1)/num;
    cout<<cnt<<"\n";
    return 0;
}
