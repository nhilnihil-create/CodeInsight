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

vector<ll> memo(100005,-INF);

ll f(ll x){
    if(x==0 || x==1) return 1;
    else if(memo[x]!=-INF) return memo[x];
    else{
        return memo[x]=(f(x-1)+f(x-2))%MOD;
    }
}

int main(){
    ll N,M; cin>>N>>M;
    ll ans=1;
    vector<ll> A(M);
    
    rep(i,M){
        cin>>A[i];
        if(i>=1 && A[i]==A[i-1]+1){
            cout<<0<<endl;
            return 0;
        }
    }
    A.pb(N+1);
    // 0~A[0]-1,A[0]+1~A[1]-1,....,A[M-1]+1~N(=A[M]-1)
    rep(i,M+1){
        if(i==0){
            ans*=f(A[0]-1);
            ans%=MOD;
        }
        else{
            ans*=f(A[i]-A[i-1]-2);
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}


