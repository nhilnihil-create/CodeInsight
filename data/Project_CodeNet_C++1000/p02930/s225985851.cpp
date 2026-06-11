#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }




int main() {
    
    
    
    int n;
    cin >> n;
    
    int table[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int nn = 0;
    rep(i, 10) if (table[i] > n) { nn = i; break; }
    // cout << nn << endl;
    
    // 下位bitから1, 2, ...って割り振るか
    
    int a[n][n];
    fill_n(*a, n * n, 0);
    
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            rep(k, nn) {
                if ((i & (1 << k)) == ((j & (1 << k)))) {
                    continue;
                } else {
                    a[i][j] = k + 1;
                    break;
                }
            }
        }
    }
    rep(i, n - 1) {
        rep3(j, i + 1, n) {
            if (j > i + 1) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
}

