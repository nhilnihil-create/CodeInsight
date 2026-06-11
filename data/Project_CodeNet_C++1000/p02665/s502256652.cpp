#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define repB(i, z, n) for(int i = n - 1; i >= z; i--)
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
    int N;
    cin >> N;
    vector<int64_t> A(N + 1), small(N + 1), big(N + 1), B(N + 1);
    rep(i, 0, N + 1) cin >> A.at(i);
    
    small.at(N) = A.at(N);
    big.at(N) = A.at(N);
    repB(i, 0, N){
        small.at(i) = (small.at(i + 1) + 1)/ 2 + A.at(i);
        big.at(i) = big.at(i + 1) + A.at(i);
    }
    if((1 < small.at(0)) || (1 > big.at(0))){
        cout << -1 << endl;
        return 0;
    }
    
    int64_t ans = 1;
    B.at(0) = 1;
    rep(i, 1, N + 1){
        B.at(i) = min((B.at(i - 1) - A.at(i - 1)) * 2, big.at(i));
        ans += B.at(i);
    }
    cout << ans << endl;
}