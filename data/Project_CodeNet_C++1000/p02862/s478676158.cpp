#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979

//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
//#define P pair<int, int>
typedef pair<int, int> P;

int64_t powmod(int64_t x, int64_t n){
    //pow(x, n) % MOD
    int64_t ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int64_t nikou(int64_t A, int64_t B){
    //B Combination A
    int64_t x = 1, y = 1;
    rep(i, 0, A){
        x *= (B - i);
        y *= (i + 1);
        x %= MOD;
        y %= MOD;
    }
    y = powmod(y, MOD - 2);
    return x * y % MOD;
}

int main(){
    int X, Y;
    cin >> X >> Y;
    int64_t A, B;
    if((2 * Y - X) % 3 == 0 && (2 * X - Y) % 3 == 0){
        A = (2 * Y - X) / 3;
        B = (2 * X - Y) / 3;
        if (A < 0 || B < 0){
            cout << 0 << endl;
            return 0;
        }
    }
    else{
        cout << 0 << endl;
        return 0;
    }
    if(A > B) swap(A, B);
    cout << nikou(A, A + B)<< endl;
}