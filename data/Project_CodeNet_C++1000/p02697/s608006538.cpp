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

int main(){
    int n, m;
    cin >> n >> m;
    int a = (m + 1) / 2;
    for (int i = 0; i < a; ++i) {
        cout << i+1 << " " << i+1 + 2*(a-i-1) + 1 << endl;
    }
    for (int i = 0; i < m / 2; ++i) {
        cout << 2*a + 1 + i << " " << 2*a + 1 + i + 2*(m/2-i-1) + 2 << endl;
    }
}

