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

bool solve(ll N, ll K, ll mid, vector<ll> &A, vector<ll> &F){
    rep(i,N){
        ll now = A[i]*F[i];
        if(now <= mid) continue;
        K -= A[i] - mid/F[i];
    }
    if(K < 0) return false;
    else return true;
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),F(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());
    ll left = -1;
    ll right = 1000000000005;
    while(right-left>1){
        ll mid = (right + left) / 2;
        if(solve(N, K, mid, A, F)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}