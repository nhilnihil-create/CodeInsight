#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<class U, class V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

bool isPowerOf2(int n) {
    while(n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

int main() {
    int N; cin >> N;
    if(isPowerOf2(N)) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    vector<pii> edges;
    // make chain [1' - 2' - 3' - 1 - 2 - 3]
    edges.push_back({N + 1, N + 2});
    edges.push_back({N + 2, N + 3});
    edges.push_back({N + 3, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    // connect {2*k} - {2*k + 1} to 1
    for(int i = 4; i <= N - 1; i += 2) {
        // 1 - i - (i+1) & 1 - (i+1)' - i'
        edges.push_back({1, i});
        edges.push_back({i, i + 1});
        edges.push_back({1, N + i + 1});
        edges.push_back({N + i + 1, N + i});
    }
    if(N % 2 == 0) {
        int a = 1, b = 1;
        while(true) {
            if(a < N) a <<= 1;
            else break;
        }
        a >>= 1;
        b = N^a^1;
        // connect N - a - 1 - b' - N'
        edges.push_back({N, a});
        edges.push_back({N + b, N + N});
    }
    for(auto &e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
}
