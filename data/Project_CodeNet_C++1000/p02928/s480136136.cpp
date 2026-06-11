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
#define INF 1000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<pair<ll,ll>> cnt(N);
    rep(i,N){
        ll now = A[i];
        ll sum = 0;
        ll kou = 0;
        rep(j,N){
            if(i == j) continue;
            if(now > A[j]){
                if(i < j){
                    sum++;
                    kou++;
                }
                else sum++;
            }
        }
        cnt[i] = {sum,kou};
    } 
    ll k_sum = (K-1)*K/2;
    k_sum %= MOD;
    ll ans = 0;
    rep(i,N){
        ans += (k_sum * cnt[i].first % MOD + cnt[i].second * K % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}