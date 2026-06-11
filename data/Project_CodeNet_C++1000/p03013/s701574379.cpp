#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
#define ll long long
using namespace std;

int main(){
    ll n,m;
    ll mod=1000000007;
    cin>>n>>m;
    vector<int>a(m);
    rep(i,m)cin>>a[i];
    vector<ll>dp(n+1,1);
    rep(i,m)dp[a[i]-1]=0;
    if(dp[0]==0&&dp[1]==0){cout<<"0";return 0;}
    for(int i=1;i<n;i++){
        if(i==1&&dp[0]==1&&dp[i]!=0){dp[i]=2;continue;}
        if(i==1&&dp[0]==0&&dp[i]!=0){dp[i]=1;continue;}
        if(dp[i]!=0)dp[i]=(dp[i-1]+dp[i-2])%mod;}
    cout<<dp[n-1];
    return 0;
}