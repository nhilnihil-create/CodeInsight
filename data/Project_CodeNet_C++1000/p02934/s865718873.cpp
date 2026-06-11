// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll  a,b,c,d,e,n,k,maxi=0,f=0,mini=INF,sum=0,q;
	string str,stra,straa;
    ll x,y,z;
    char ca,cb,cc;
    cin>>n;
    vector<long double> v(n);
    rep(i,n) cin>>v[i];
    vector<long double> ld(n);
    rep(i,n) ld[i]=(long double)1/(long double)v[i];
    cout<<1/(long double)accumulate(ld.begin(),ld.end(),(long double)0);


    return 0;
}
