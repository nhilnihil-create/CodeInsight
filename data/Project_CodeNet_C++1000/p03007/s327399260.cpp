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
#define INF 9223372036854775807
#define MOD 998244353
#define mod 1000000007
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) fo-r (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
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
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<ll,ll> a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi>b.fi;
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //-------------------------------
    ll n;cin>>n;
    V<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    ll ans=0;
    ans=a[0];
    V<Pll>out;


    if(a[n-1]<=0){
        ans=a[n-1];
        for(ll i=n-2;i>=0;i--){
            out.pb(mp(ans,a[i]));
            ans-=a[i];
        }
        cout<<ans<<endl;
        for(ll i=0;i<n-1;i++){
            cout<<out[i].fi<<" "<<out[i].se<<endl;
        }
        return 0;
    }



    ll l=0,r=0;
    for(ll i=1;i<n-1;i++){
        if(a[i]>=0){
            l=ans;
            r=a[i];
            ans-=a[i];
            out.pb(mp(l,r));
        }
    }  
        r=ans;
        l=a[n-1];
        ans=a[n-1]-ans;
        out.pb(mp(l,r));
    
    for(ll i=1;i<n-1;i++){
        if(a[i]<0){
            l=ans;
            r=a[i];
            ans-=a[i];
            out.pb(mp(l,r));
        }
    }
    cout<<ans<<endl;
    for(ll i=0;i<n-1;i++){
        cout<<out[i].fi<<" "<<out[i].se<<endl;
    }
    //-------------------------------
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------
















































