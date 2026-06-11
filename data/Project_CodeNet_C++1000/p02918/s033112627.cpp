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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int lr = 0;
    int rl = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (i < n-1) {
            if (s[i] == 'L' && s[i+1] == 'R') lr++;
            if (s[i] == 'R' && s[i+1] == 'L') rl++;
        }
        if (i > 0 && s[i] == 'L') {
            if (s[i-1] == 'L') res++;
        }
        if (i < n-1 && s[i] == 'R') {
            if (s[i+1] == 'R') res++;
        }
    }

    for (int i = 0; i < k; ++i) {
        if (lr > 0 && rl > 0) {
            res += 2;
            lr--; rl--;
        } else if (lr > 0) {
            res += 1;
            lr--;
        } else if (rl > 0) {
            res += 1;
            rl--;
        } else {
            break;
        }
    }
    cout << res << endl;
}