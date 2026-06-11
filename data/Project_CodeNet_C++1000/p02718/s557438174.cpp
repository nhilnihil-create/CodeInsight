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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    double limit = (double)sum / (4.0 * (double)m);
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if ((double)a[i] >= limit) num++;
    }
    if (num >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
}