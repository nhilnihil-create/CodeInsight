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
    vector<ll>b(a),c(a);
    rep(i,a){
        ll d,e;
        cin>>d>>e;
        b[i]=d+e;
        c[i]=d-e;
    }
    sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        ll ans=max(abs(b[0]-b[a-1]),abs(c[0]-c[a-1]));
        cout<<ans;
}