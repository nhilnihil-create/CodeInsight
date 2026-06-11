#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n;
    cin>>n;
    int d=n-1,t=2,cnt=0;
    while(t<=d){
        cnt+=d/t;
        t*=2;
    }
    string s;
    cin>>s;
    V<int> a(n);
    bool c=false;
    for(int i=0;i<n;i++){
        a[i]=int(s[i]-'1');
        if(a[i]==1)c=true;
    }
    if(!c)for(int i=0;i<n;i++)a[i]/=2;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=1)continue;
        d=i;t=2;int cn=0;
        while(t<=d){
        cn+=d/t;
        t*=2;
    }
    d=(n-i-1);t=2;
    while(t<=d){
        cn+=d/t;
        t*=2;
    }
    if(cn==cnt)ans^=1;
    }
    if(!c)cout<<(ans?2:0)<<"\n";
    else cout<<ans<<"\n";
}
