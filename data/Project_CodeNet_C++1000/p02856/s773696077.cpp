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
    int M;
    cin >> M;
    vector<ll> D(M), C(M);
    rep(i, 0, M) {
        cin >> D[i] >> C[i];
    }
    ll digits = 0;
    ll sum = 0;
    rep(i, 0, M) {
        digits += C[i];
        sum += D[i] * C[i];
    }
    cout << (digits - 1) + (sum - 1) / 9 << endl;
    return 0;
}