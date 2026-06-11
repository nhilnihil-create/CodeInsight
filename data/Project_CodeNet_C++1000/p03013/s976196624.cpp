// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
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

    ll a,b,c,d,n,maxi=0,f=0,mini=INF,sum=0;
    ll m;
    cin>>n>>m;
    vector<ll> v(m);
    set<ll> s;
    rep(i,m) {
        cin>>a;
        s.insert(a);
    }
    ll dp[1000000];
    dp[0]=1;
    rep(i,n){
        if(s.find(i+1)==s.end()) dp[i+1]+=dp[i];
        if(i!=n-1&&s.find(i+2)==s.end()) dp[i+2]+=dp[i];
        dp[i+1]%=mod;
        dp[i+2]%=mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
