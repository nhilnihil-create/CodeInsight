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
vector<ll> divisor(ll x){
    vector<ll> div;
    for(int i=1;i*i<=x;i++){
        if(i*i!=x && x%i==0){
            div.pb(i);
            div.pb(x/i);
        }
        else if(x%i==0) div.pb(i);
    }
    return div;
}
vector<ll> vectorprime(ll x){
    vector<bool> is_prime(x+1);
    vector<ll> prime;
    rep(i,x+1) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=x;i++){
        if(is_prime[i]){
            prime.pb(i);
        }
        for(int j=i*2;j<=x;j+=i) is_prime[j]=false;
    }
    return prime;
}

int main(){
    {rep1(i,50) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N;
    ll ans=0;
    string S;
    cin>>N>>S;
    
    vector<ll> R;
    vector<ll> G;
    vector<ll> B;
    rep(i,sz(S)){
        if(S[i]=='R') R.pb(i+1);
        else  if(S[i]=='G') G.pb(i+1);
        else B.pb(i+1);
    }
    if((sz(R)==0)||(sz(G)==0)||(sz(B)==0)){
        cout<<0;
        return 0;
    }
    //cout<<R[1];
    rep1(i,N){
        if(S[i-1]=='R'){
            rep(j,sz(G)){
                ll Gpoint=G[j]; //Gがある座標
                ll out_1=-1; //Bのダメなやつ1
                if(2*Gpoint-i>=1) out_1=2*Gpoint-i;
                ll out_2=-1; //Bのダメなやつ2
                if(2*i-Gpoint>=1) out_2=2*i-Gpoint;
                ll out_3=-1; //Bのダメなやつ3
                if((Gpoint-i)%2==0) out_3=(Gpoint+i)/2;
                
                ans+=sz(B);
                
                // 二分探索
                int l=0,r=sz(B)-1;
                while(r-l>=1){
                    int i=(l+r)/2;
                    if(B[i]<out_1) l=i+1;
                    else r=i;
                }
                if(B[l]==out_1) ans--;
                
                l=0,r=sz(B)-1;
                while(r-l>=1){
                    int i=(l+r)/2;
                    if(B[i]<out_2) l=i+1;
                    else r=i;
                }
                if(B[l]==out_2) ans--;
                
                l=0,r=sz(B)-1;
                while(r-l>=1){
                    int i=(l+r)/2;
                    if(B[i]<out_3) l=i+1;
                    else r=i;
                }
                if(B[l]==out_3) ans--;
            }
        }
    }
    cout<<ans<<endl;
}
