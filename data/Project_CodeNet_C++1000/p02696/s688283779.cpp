#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    ll x = min(B-1, N);
    //cout << A*(x/B) << endl;
    cout << (A*x)/B << endl;

    return 0;
}
