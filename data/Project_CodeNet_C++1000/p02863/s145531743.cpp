#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}
 
typedef pair<ll,ll> Pair;
const ll MAX_L=10000;
 

int main(){
    ll n,t;
    cin >> n >> t;
    vector<Pair> vec;
    rep(i,n){
        ll a,b;
        cin >> a >>b;
        vec.pb(make(a,b));
    }
    sort(vec.begin(),vec.end());
    ll dp[n+1][t+10];
    //初期化
    rep(i,t) dp[0][i]=0;
    
    //dp
    rep(i,n){
        rep(j,t){
            if(j<vec[i].first) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-vec[i].first]+vec[i].second);
        }
    }
    ll ans=0;
    rep(i,n){
        ans=max(ans,dp[i][t-1]+vec[i].second);
    }
    kaku(ans);
}

