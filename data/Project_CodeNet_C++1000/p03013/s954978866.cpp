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
    cin>>n>>m;
    vector<ll>a(m);
    vector<ll>dp(n,-1);
    rep(i,m){
        cin>>a[i];
        dp[a[i]-1]=0;
    }



if(dp[1]==-1&&dp[0]==-1)dp[1]=2;
if(dp[0]==-1)dp[0]=1;
if(dp[0]==0&&dp[1]==-1)dp[1]=1;
rep(i,n-2){
    if(dp[i+2]==0)continue;
    dp[i+2]=(dp[i+1]+dp[i])%1000000007;
}
cout<<dp[n-1];
return 0;

}