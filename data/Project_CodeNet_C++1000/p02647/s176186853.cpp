#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<iomanip>
#include<cstring>
#include<string>
#include<set>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll = long long int;

const ll INF = 1<<30;
const ll LINF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(void) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    if (k > 41) {
        cout << n;
        REP(i, n - 1) cout << " " << n;
        cout << endl;
    }
    else {
        REP(j, k) {
            vector<int> b(n, 0);
            REP(i, n) {
                int l = max(0, i - a[i]);
                int r = min(n - 1, i + a[i]);
                b[l]++;
                if (r + 1 < n) b[r + 1]--;
            }
            for (int i = 1; i < n; i++) b[i] += b[i - 1];
            REP(i, n) a[i] = b[i];
        }
        cout << a[0];
        for (int i = 1; i < n; i++) cout << " " << a[i];
        cout << endl;
    }
}