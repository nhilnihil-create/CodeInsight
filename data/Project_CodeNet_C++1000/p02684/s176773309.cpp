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
#define sz(x) (ll)((x).size())
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

vector<ll> pw2(62,1);vector<ll> pw10(19,1);
ll high_order_bit(ll n){
    ll tmp=1,i=-1;
    while(tmp<=n){
        tmp*=2;
        i++;
    }
    if(n==0) return 0;
    else return i;
}
vector<ll> binary_expansion(ll n){
    vector<ll> B(high_order_bit(n)+1);
    ll tmp=n;
    for(ll i=high_order_bit(n);i>=0;i--){
        B[i]=tmp/pw2[i];
        tmp%=pw2[i];
    }
    return B;
}

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,K; cin>>N>>K;
    ll ans=0;
    vector<ll> A(N+1,0);
    rep1(i,N) cin>>A[i];
    
    //doubling[i][j]:jから2^i回でどこにいるか
    ll D_MAX=65; //2^D_MAXで辿り着ける
    vector<vector<ll> > doubling(D_MAX+1,vector<ll>(N+1,0));
    
    //[0][j]は入力から作る
    rep1(j,N) doubling[0][j]=A[j];
    
    //前処理
    //1つ前の時間の情報がいるからiからループ
    rep1(i,D_MAX)rep1(j,N){
        doubling[i][j]=doubling[i-1][doubling[i-1][j]];
    }
    
    //solve
    //1からK回
    vector<ll> v=binary_expansion(K);
    ll now=1;
    rep(i,sz(v)){
        if(v[i]==1) now=doubling[i][now];
    }
    cout<<now<<endl;
    
}

