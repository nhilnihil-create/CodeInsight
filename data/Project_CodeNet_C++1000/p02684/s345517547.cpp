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
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
vector<ll> pw2(51,1);vector<ll> pw10(19,1);


int main(){
    {rep1(i,50) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,K; cin>>N>>K;
    ll ans=0;
    vector<ll> A(N+1,0);
    rep1(i,N) cin>>A[i];
    
    vector<ll> visited(N+1,INF);
    ll now=1;
    ll rotate,times;
    visited[now]=0;
    rep1(i,N){
        now=A[now];
        if(i==K){
            cout<<now<<endl;
            return 0;
        }
        
        if(visited[now]==INF) visited[now]=i;
        else{
            rotate=now;
            times=i;
            break;
        }
    }
    //visited[rotate]~times回でrotateに戻る
    ll L=times-visited[rotate];
    rep1(i,(K-visited[rotate])%L){
        now=A[now];
    }
    cout<<now<<endl;
}

