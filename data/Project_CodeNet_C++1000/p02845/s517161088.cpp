#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000
#define MAX 200001
#define PI 3.141592653589793

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    int color_1 = -1;
    int color_2 = -1;
    int color_3 = -1;
    vector<int> dp(N+1,0);
    dp[0] = 1;
    rep(i,N){
        ll ka = 0;
        int now = A[i];
        if(color_1 == now-1){
            ka++;
            color_1++;
            if(color_2 == now-1) ka++;
            if(color_3 == now-1) ka++;
        } 
        else if(color_2 == now-1){
            ka++;
            color_2++;
            if(color_3 == now-1) ka++;
        }
        else if(color_3 == now-1){
            ka++;
            color_3++;
        }
        dp[i+1] = dp[i] * ka % MOD;
        dp[i+1] %= MOD;
    }
    //cout << color_1 << color_2 << color_3 << endl;
    cout << dp[N] << endl;
}