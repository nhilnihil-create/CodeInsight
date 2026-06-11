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
long long modinv(long long a){
    long long b=MOD,u=1,v=0;
    while(b){
      long long t=a/b;
      a-=t*b;
      swap(a,b);
      u-=t*v;
      swap(u,v);
    }
    u%=MOD;
    if(u<0) u+=MOD;
    return u;
}
 
long long dev(long long a,long long b){
    return (a*modinv(b))%MOD;
}
 
long long comb(int x,int y){
  long long tmp=1;
    for(int i=0;i<y;i++){
        tmp=dev(tmp*(x-i)%MOD,i+1);
    }
  return tmp;
}
int main(){
    ll X,Y; cin>>X>>Y;
    if((X+Y)%3!=0) cout<<0;
    else if((X>2*Y)||(Y>X*2)) cout<<0;
    else{
        ll t=(X+Y)/3;
        ll B=(2*Y-X)/3;
        if((2*Y-X)%3!=0){
            cout<<0;
            return 0;
        }
        ll A=t-B;
        if(A<0){
            cout<<0;
            return 0;
        }
        cout<<comb(t,A);
    }
}


