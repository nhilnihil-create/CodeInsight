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
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B), x(M), y(M), c(M);
    rep(i, 0, A) cin >> a.at(i);
    rep(i, 0, B) cin >> b.at(i);
    rep(i, 0, M) cin >> x.at(i) >> y.at(i) >> c.at(i);
    int fin = INF;
    rep(i, 0, M){
        int sum = a.at(x.at(i) - 1) + b.at(y.at(i) - 1) - c.at(i);
        fin = min(fin, sum);
    }
    int min_a = *min_element(all(a));
    int min_b = *min_element(all(b));
    fin = min(fin, min_a + min_b);
    cout << fin << endl;
}