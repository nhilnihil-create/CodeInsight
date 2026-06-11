#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0) {
        cout << (b - a) / 2 << endl;
    } else {
        cout << min(a - 1, n - b) + 1 + (b - a - 1) / 2 << endl;
    }
    
    return 0;
}