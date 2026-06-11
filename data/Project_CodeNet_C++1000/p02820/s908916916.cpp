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
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    int res = 0;
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i) {
        if (t[i] == 'r'){
            if (i >= k && t[i-k] == 'r' && !v[i-k]){
                v[i] = true;
                continue;
            }
            res += p;
        }
        if (t[i] == 's'){
            if (i >= k && t[i-k] == 's' && !v[i-k]){
                v[i] = true;
                continue;
            }
            res += r;
        }
        if (t[i] == 'p'){
            if (i >= k && t[i-k] == 'p' && !v[i-k]){
                v[i] = true;
                continue;
            }
            res += s;
        }
    }
    cout << res << endl;
}