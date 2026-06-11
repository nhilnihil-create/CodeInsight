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
    int N, M;
    cin >> N >> M;
    vector<int> p(M);
    vector<string> S(M);
    REP(i, M) {
        cin >> p[i] >> S[i];
        p[i]--;
    }
    vector<bool> ac(N, false);
    vector<int> wa(N);
    REP(i, M) {
        if(ac[p[i]] == false && S[i] == "WA") wa[p[i]]++;
        else if(ac[p[i]] == false && S[i] == "AC") ac[p[i]] = true;
    }
    int n_ac = 0, n_wa = 0;
    REP(i, N) {
        if(ac[i]) {
            n_ac++;
            n_wa += wa[i];
        }
    }
    cout << n_ac << " " << n_wa << endl;
    return 0;
}