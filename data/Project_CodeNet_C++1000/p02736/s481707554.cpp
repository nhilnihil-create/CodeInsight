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
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

vector<int> a;

// nCkの偶奇
int parity(int n, int k) { return (n & k) == k; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        --a[i];
    }
    int oe = 0;
    for(int i = 0; i < n; i++) {
        oe ^= parity(n - 1, i) * a[i] % 2;
    }
    if(oe == 1) {
        cout << 1 << endl;
        return 0;
    }
    bool oneExist = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            oneExist = true;
        }
    }
    if(oneExist) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        a[i] /= 2;
    }
    oe = 0;
    for(int i = 0; i < n; i++) {
        oe ^= parity(n - 1, i) * a[i] % 2;
    }
    cout << (oe ? 2 : 0) << endl;
}