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
vector<ll> pw3(15,1);vector<ll> pw10(19,1);
int main(){
    {rep1(i,14) pw3[i]=3*pw3[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    ll ans=0;
    vector<ll> P(N+1);
    vector<ll> place(N+1); //place[x]:xがある場所
    rep1(i,N){
        cin>>P[i];
        place[P[i]]=i;
    }
    
    multiset<ll> se;
    se.insert(0);
    se.insert(0);
    se.insert(N+1);
    se.insert(N+1);
    se.insert(place[N]);
    rrep1(i,N-1){
        ll X=place[i]; //場所
        // m2 m1 X M1 M2 :座標
        auto it=se.upper_bound(X);
        ll M1=*(it);
        it++;
        ll M2=*(it);
        it--;
        it--;//*(se.lower_bound(M1));
        ll m1=*(it);
        it--;
        ll m2=*(it);
        
        //cout<<m2<<" "<<m1<<" "<<X<<" "<<M1<<" "<<M2<<endl;
        
        ans+=i*((X-m1)*(M2-M1)+(M1-X)*(m1-m2));
        
        se.insert(X);
    }
    
    cout<<ans<<endl;
}
