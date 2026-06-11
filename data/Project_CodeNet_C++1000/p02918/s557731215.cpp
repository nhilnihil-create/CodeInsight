#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    int LR = 0, RL = 0;
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            ans++;
        } else if(s[i] == 'L' && s[i + 1] == 'R') {
            LR++;
        } else if(s[i] == 'R' && s[i + 1] == 'L') {
            RL++;
        }
    }
    int mn = min(LR, RL);
    if(k <= mn) {
        ans += 2 * k;
    } else {
        ans = n - 1;
    }
    print(ans);
}