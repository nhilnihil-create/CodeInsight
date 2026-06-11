#include<iostream>
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
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll  long long 
const ll INF=1LL<<60;
const ll MOD=1000000007;
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
ll dp[2001];
int main(){
    ll a;cin>>a;
    dp[1]=0;
    dp[2]=0;
    dp[3]=1;
    dp[4]=1;
    if(a<=4)cout<<dp[a];
    else{for(ll i=5;i<=a;i++){
        dp[i]=dp[i-2]+dp[i-3]+dp[i-4];
        dp[i]%=MOD;
    }
    cout<<dp[a];
}}
