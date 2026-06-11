#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

int main(){
    ll N,M; cin>>N>>M;
    vector<ll> A(M);
    vector<ll> f(N+1,-INF);
    f[0]=1;
    rep(i,M){
        cin>>A[i];
        f[A[i]]=0;
    }
    if(f[1]!=0) f[1]=1;
    
    FOR(i,2,N+1){
        if(f[i]!=0){
            f[i]=f[i-2]+f[i-1];
            f[i]%=MOD;
        }
    }
    
    cout<<f[N]<<endl;
}


