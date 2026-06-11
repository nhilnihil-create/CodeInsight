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
const int MAX = 5000000;
long long moto[MAX], gyaku[MAX], inv[MAX];
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
void ncr_shokika() {
    moto[0] = moto[1] = 1;
    gyaku[0] = gyaku[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        moto[i] = moto[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        gyaku[i] = gyaku[i - 1] * inv[i] % MOD;
    }
}
long long ncr(int n, int r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return moto[n] * (gyaku[r] * gyaku[n - r] % MOD) % MOD;
}
int main(){
    ll a,b;cin>>a>>b;
    if((a+b)%3!=0){
        cout<<0;
        return 0;
    }
    ll c=a+b;
    ll d=c/3;
    ll e=a-b;
    ll f=(d-e)/2;
    ll g=(d+e)/2;
    ncr_shokika();
    cout<<ncr(d,f)<<endl;
}