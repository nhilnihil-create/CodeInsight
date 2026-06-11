#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int next_combination(int bit) {
    int x = bit & -bit, y = bit + x;
    return (((bit & ~y) / x) >> 1) | y;
} /*(1<<k)-1から列挙*/

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    int bit = (1<<n)- 1;
    int res = 0;
    while (bit < 1<<(n+m-1)){
        int now = 1;
        vector<int> A;
        for (int i = 0; i < n+m-1; ++i) {
            if (bit & (1<<i)) A.push_back(now);
            else now++;
        }

        int tmp = 0;
        for (int i = 0; i < q; ++i) {
            if (A[b[i]] - A[a[i]] == c[i]) tmp += d[i];
        }
        chmax(res, tmp);

        bit = next_combination(bit);
    }
    cout << res << endl;
}