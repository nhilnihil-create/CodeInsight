#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using Pii = pair<int, int>;
using Pil = pair<int, ll>;
using Pid = pair<int, ld>;
using Pis = pair<int, string>;

const int INF = 1 << 28;
const ll INF_L = 1LL << 60;
const int MOD = 1e9+7;

// ----------------------------------------------------------------
// Dynamical Programming
// ----------------------------------------------------------------
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Graph Theory
// ----------------------------------------------------------------
vector<vector<int>> adjMat;
vector<set<Pii>> adjList;

void Dijkstra(){}
void BellmanFord(){}
void WarshallFloyd(){}
// ----------------------------------------------------------------


// ----------------------------------------------------------------
// Mathematical Functions
// ----------------------------------------------------------------
ll gcd(ll A, ll B) {if (A%B == 0) {return(B);} else {return(gcd(B, A%B));}}
ll lcm(ll A, ll B) {return A * B / gcd(A, B);}

ll powMod(ll B, ll P) {
    if(P == 0) return 1;
    if(P%2 == 0){ll t = powMod(B, P/2); return t*t % MOD;}
    return B * powMod(B, P-1) % MOD;
}

/* ----------------------------------
 Factorial, Permutation, Combination
 ---------------------------------- */
const int FAC_INIT_SIZE = 5e6+9;
vector<ll> fac, finv, inv;

void factModInit() {
    fac.resize(FAC_INIT_SIZE);
    finv.resize(FAC_INIT_SIZE);
    inv.resize(FAC_INIT_SIZE);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i < FAC_INIT_SIZE; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll factMod(ll N){return fac[N] % MOD;}
ll factInvMod(ll N){return finv[N] % MOD;}
ll permMod(ll N, ll K){
    if (N < 0 || K < 0 || N < K) return 0;
    else return factMod(N) * factInvMod(N-K) % MOD;
}
ll combMod(ll N, ll K){
    if (N < 0 || K < 0 || N < K) return 0;
    else if (N < FAC_INIT_SIZE){ return factMod(N) * (factInvMod(K) * factInvMod(N-K) % MOD) % MOD;}
    else {
        ll ans = 1; ll Ks = K < N-K ? K : N-K;
        for (ll i=N; i > N-Ks; i--) {ans *= i; ans %= MOD;}
        return ans * factInvMod(Ks) % MOD;
    }
}
// ----------------------------------------------------------------


int main() {
    
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<Pii> A(N);
    for(int i=0; i<N; i++) {int a; cin >> a; A[i] = make_pair(a, i+1);}
    sort(A.begin(), A.end());
    for(int i=0; i<N; i++) cout << A[i].second << " ";
}
