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

int main(){
    double a, b, x, ans;
    cin >> a >> b >> x;
    double c = a * a * b / 2;
    if (c >= x){
        ans = atan(a * pow(b, 2) / (2 * x)) * 360 / (2 * PI);
    }
    else{
        ans = atan(2 * ((pow(a, 2) * b - x) / pow(a, 3))) * 360 / (2 * PI);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
