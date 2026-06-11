#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, k;
    cin >> n >> k;
    vector<bool> v(n, false);
    int d, a;
    for (int i = 0; i < k; ++i) {
        cin >> d;
        for (int j = 0; j < d; ++j) {
            cin >> a;
            v[--a] = true;
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) res++;
    }
    cout << res << endl;
}