#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

vector<vector<vector<int>>> dp(90, vector<vector<int>>(90, vector<int>(25700)));
vector<vector<int>> A(90, vector<int>(90));
vector<vector<int>> B(90, vector<int>(90));


int main() {
    ll n; cin >> n;
    if(n % 2 == 1ll) {
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    n /= 2ll;
    while(n > 0) {
       n /= 5ll;
       res += n;
    }
    cout << res << endl;
    return 0;
}
