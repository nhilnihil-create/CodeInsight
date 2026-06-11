#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N, K, C;
    string S;
    cin >> N >> K >> C >> S;

    vector<int> constraints_backward(N); 
    int must = K;
    int k = K+1, last_k_idx = N;
    FORR(i, N-1, 0) {
        if(S[i] == 'o') {
            if(last_k_idx == N || i < last_k_idx - C) {
                // constraints_backward[i] = constraints_backward[i + C] - 1;
                constraints_backward[i] = --k;
                last_k_idx = i;
            } else {
                constraints_backward[i] = k;
            } 
        }
    }

    vector<int> constraints_forward(N);
    k = 0;
    int first_k_idx = -1;
    FOR(i, 0, N-1) {
        if(S[i] == 'o') {
            if(i > first_k_idx + C || first_k_idx == -1) {
                constraints_forward[i] = ++k;
                first_k_idx = i;
            } else {
                constraints_forward[i] = k;
            }
       }
    }

    vector<vector<int> > ans(K+1);
    REP(i, N) {
        if(S[i] == 'o' && constraints_backward[i] > 0 && constraints_backward[i] == constraints_forward[i])
            ans[constraints_backward[i]].push_back(i);
    }

    FOR(k, 1, K) {
        if(ans[k].size() == 1) cout << ans[k][0] + 1 << endl;
    }

    return 0;
}