#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <numeric>
#define IINF 1000000000
#define INF 3223372036854775807
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) fo-r (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
//#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
#define bit(n,k) ((n>>k)&1)
#define lg length()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<Pll,ll> a,pair<Pll,ll> b){
        return a.fi.se>b.fi.se;
}
ll cmp2(pair<ll,ll> a,pair<ll,ll> b){
    if(a.se!=b.se)
        return a.se<b.se;
    else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int main(int argc, char * argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("big.txt", "r", stdin);
    //freopen("out3.txt", "w", stdout);
    //-----------------------------
    ll n,k;cin>>n>>k;
    V<ll>a(n);
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=1;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0){
            V<ll>cal;
            for(ll q=0;q<n;q++){
                cal.pb(a[q]%i);
            }
            sort(all(cal));
            ll sum1[n],sum2[n];
            sum1[0]=cal[0];
            for(ll q=1;q<n;q++){
                sum1[q]=sum1[q-1]+cal[q];
            }
            sum2[n-1]=i-cal[n-1];
            for(ll q=n-2;q>=0;q--){
                sum2[q]=sum2[q+1]+i-cal[q];
            }
            bool abc=0;
            for(ll q=0;q<n-1;q++){
                if(sum1[q]==sum2[q+1]&&sum1[q]<=k){
                    abc=1;
                    break;
                }
            }
            if(abc==1){
                chmax(ans,i);
            }
            if(sum/i!=i){
                ll j =  sum/i;
                cal.clear();
                for(ll q=0;q<n;q++){
                    cal.pb(a[q]%j);
                }
                sort(all(cal));
                sum1[0]=cal[0];
                for(ll q=1;q<n;q++){
                    sum1[q]=sum1[q-1]+cal[q];
                }
                sum2[n-1]=j-cal[n-1];
                for(ll q=n-2;q>=0;q--){
                    sum2[q]=sum2[q+1]+j-cal[q];
                }
                abc=0;
                for(ll q=0;q<n-1;q++){
                    if(sum1[q]==sum2[q+1]&&sum1[q]<=k){
                        abc=1;
                        break;
                    }
                }
                if(abc==1){
                    chmax(ans,j);
                }
            }
        }
    }
    cout<<ans<<Endl;
    //------------------------------
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //------------------------------- 
    return 0;
}
//----------------------------------------------------------------------




































