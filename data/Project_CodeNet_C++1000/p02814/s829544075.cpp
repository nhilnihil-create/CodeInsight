#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e15;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(void) {
    ll n, m, a; cin >> n >> m;
    vector<int> v;
    rep(i, n) {
        cin >> a; a /= 2;
        v.push_back(a);
    }while (v[0] % 2 == 0) {
        rep(i, n) {
            if (v[i] % 2 != 0) {
                cout << 0 << endl;
                return 0;
            }v[i] /= 2;
        }m /= 2;
    }rep(i, n) {
        if (v[i] % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }ll lcm = 1;
    rep(i, n) {
        lcm = lcm / gcd(lcm, v[i]) * v[i];
        if (lcm > m) {
            cout << 0 << endl;
            return 0;
        }
    }cout << (m / lcm + 1) / 2<<endl;
}