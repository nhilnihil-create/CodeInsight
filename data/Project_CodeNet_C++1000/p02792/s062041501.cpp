#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
//const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef pair<int64_t, int64_t> P;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> c(11, vector<int>(11));
    rep(i, 1, N + 1){
        string S = to_string(i);
        int start = S.at(0) - 48;
        int end = S.at(S.size() - 1) - 48;
        //cout << start << " " << end << endl;
        c.at(start).at(end)++;
    }
    
    int64_t ans = 0;
    rep(i, 1, 10){
        rep(j, 1, 10){
            ans += c.at(i).at(j) * c.at(j).at(i);
        }
    }
    cout << ans << endl;
}