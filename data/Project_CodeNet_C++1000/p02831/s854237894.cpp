#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a,ll b){
    if(b==0){return a;}
    else{return gcd(b,a%b);}
}

int main(){
    ll a,b;cin>>a>>b;
    cout<<a*b/gcd(a,b)<<endl;
    return 0;
}