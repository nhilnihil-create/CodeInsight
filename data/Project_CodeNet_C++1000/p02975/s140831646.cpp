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
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    vector<ll> A(N);
    set<ll> se;
    rep(i,N){
        cin>>A[i];
        se.insert(A[i]);
    }
    
    bool ans=false;
    
    if(sz(se)==1){
        for(auto x:se){
            if(x==0) ans=true;
        }
    }
    else if(sz(se)==2){
        if(N%3==0){
            ll cnt0=0;
            rep(i,N){
                if(A[i]==0) cnt0++;
            }
            if(cnt0==0){}
            else if(cnt0==N/3) ans=true;
        }
    }
    else if(sz(se)==3){
        ll X[3];
        ll cnt=0;
        for(auto x:se){
            X[cnt]=x;
            cnt++;
        }
        
        if((X[0]^X[1])==X[2] && (X[0]^X[2])==X[1] && (X[2]^X[1])==X[0]){
            ll cnt0=0,cnt1=0,cnt2=0;
            rep(i,N){
                if(A[i]==X[0]) cnt0++;
                else if(A[i]==X[1]) cnt1++;
                else cnt2++;
            }
            
            if((cnt0 == cnt1) && (cnt1==cnt2) && (cnt2==cnt0)) ans=true;
        }
    }
    
    if(ans) cout<<"Yes";
    else cout<<"No";
}

