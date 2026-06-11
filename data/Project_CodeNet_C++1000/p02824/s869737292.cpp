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
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<ll> A(n);
    REP(i, n) cin >> A[i];
    sort(A.rbegin(), A.rend());

    // A[lb]: 採用可能, A[ub]: 採用不可能 
    int lb = 0, ub = n;
    while(ub > lb+1) {
        int x = (lb + ub) / 2;
        ll tmp = m * ((p - 1) + (n - 1 - x));
        FOR(i, p-1, x-1) {
            tmp += A[x] + m - A[i];
        }

        if(x <= p - 1) {
            lb = x;
        }
        else if((A[x] + m < A[p-1]) || (tmp < m * (v - 1) )) {
            ub = x;
        } else {
            lb = x;
        }
    }
    cout << lb + 1 << endl;

    return 0;
}
