#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    ll ans = 0;
    ll U, V;
    rep(i, 0, N - 1) {
        cin >> U >> V;
        if (U > V) {
            swap(U, V);
        }
        ans -= U * (N - V + 1);
    }
    rep(i, 0, N) {
        ans += (ll)(i + 1) * (N - i);
    }
    cout << ans << endl;
    return 0;
}