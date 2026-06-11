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
#define IINF 10e8
#define INF 10000000000000
#define MOD 1000000007
#define mod 1000000007
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
int dp1[3030][3030];
int dp2[3030][3030];
bool color[3030];
//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_time=clock();
    //-------------------------------
    int n,t;cin>>n>>t;
    V<Pin>food(n+1);
    for(int i=1;i<=n;i++){
        cin>>food[i].fi>>food[i].se;
    }
    int ans=0;
    sort(all(food));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t-1;j++){
            if(j>=food[i].fi){
                dp1[i][j]=mmax(dp1[i-1][j],dp1[i-1][j-food[i].fi]+food[i].se);
            }
            else{
                dp1[i][j]=dp1[i-1][j];
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=t-1;j++){
            if(j>=food[i].fi){
                dp2[i][j]=mmax(dp2[i+1][j],dp2[i+1][j-food[i].fi]+food[i].se);
            }
            else{
                dp2[i][j]=dp2[i+1][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t-1;j++){
            chmax(ans,dp1[i-1][j]+dp2[i+1][t-1-j]+food[i].se);
        }
    }
    cout<<ans<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------












































