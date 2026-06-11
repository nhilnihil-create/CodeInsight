#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n)  FOR(i, 0, n)
#define ASC(c) sort((c).begin(), (c).end())
#define DESC(c) sort((c).begin(), (c).end(), greater<int>())

#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
    int A, B, m; cin >> A >> B >> m;
    vector<int> a(A), b(B);
    REP(i, A) cin >> a[i];
    REP(i, B) cin >> b[i];

    int ans = *std::min_element(a.begin(), a.end()) + *std::min_element(b.begin(), b.end());;

    REP(_, m) {
        int x, y, c; cin >> x >> y >> c;
        ans = min(ans, a[x - 1] + b[y - 1] - c);
    }
    cout << ans << endl;
}
