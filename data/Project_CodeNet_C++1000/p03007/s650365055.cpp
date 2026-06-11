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
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);vector<ll> pw_2(62,1);


int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,61) pw_2[i]=-2*pw_2[i-1];}
    
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(all(A));
    // 0 1 2 ..... N-1
    // - ? ?        +
    vector<ll> sign(N,0);
    ll plus=1;
    sign[0]=-1;
    sign[N-1]=1;
    rep1(i,N-2){
        if(A[i]<0) sign[i]=-1;
        else{
            plus++;
            sign[i]=1;
        }
    }
    
    //Mだす
    ll M=0;
    rep(i,N){
        M+=sign[i]*A[i];
    }
    cout<<M<<endl;
    
    //[0] - (+) - (+) - (+) ...... = tmp
    //[1]~ (マイナスのやつ)　- tmp
    ll tmp=A[0];
    for(ll i=N-2;i>=N-plus;i--){
        cout<<tmp<<" "<<A[i]<<endl;
        tmp-=A[i];
    }
    
    cout<<A[N-1]<<" "<<tmp<<endl;
    tmp=A[N-1]-tmp;
    
    rep1(i,N-plus-1){
        cout<<tmp<<" "<<A[i]<<endl;
        tmp-=A[i];
    }
}

