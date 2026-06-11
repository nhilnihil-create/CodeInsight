#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, long long M) {
    if (M % 2 == 0) {
        repn(i, M / 2) { cout << i << " " << M + 1 - i << endl; }
        repn(i, M / 2) { cout << M + i << " " << 2 * M + 2 - i << endl; }
    } else {
        repn(i, M / 2 + 1) { cout << i << " " << M + 2 - i << endl; }
        repn(i, M / 2) { cout << M + 1 + i << " " << 2 * M + 2 - i << endl; }
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    solve(N, M);
    return 0;
}
