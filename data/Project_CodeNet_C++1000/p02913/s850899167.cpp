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
    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int len = 0;
        for (int j = 0; j < n-i; ++j) {
            if (s[j] == s[j+i] && len < i) {
                len++;
            } else {
                len = 0;
            }
            chmax(res, len);
        }
    }
    cout << res <<endl;
}