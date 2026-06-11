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
    int X;
    cin >> X;
    rep(i, 0, 1001) {
        int rest = X - 100 * i;
        if (rest < 0) {
            continue;
        } else if (rest <= 5 * i) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}