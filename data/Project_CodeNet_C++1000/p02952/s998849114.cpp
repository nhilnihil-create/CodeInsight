#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int digit(int n) {
    int ret = 0;
    while (n > 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (digit(i) % 2 == 1) res++;
    }
    cout << res << endl;
}