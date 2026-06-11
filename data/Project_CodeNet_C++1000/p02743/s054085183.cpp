#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

int main() {
    long double a,b,c;
    cin >> a >> b >> c;
    long double eps = 1.0E-14;
    if (pow(a,0.5) + pow(b,0.5) + eps < pow(c,0.5)) cout << "Yes" << endl;
    else cout << "No" << endl;
}