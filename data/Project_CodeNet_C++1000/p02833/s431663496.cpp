#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int max_a = 20005;

int main(){
    ll N; cin >> N;
    if (N%2==1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    N /= 2;
    while (N > 0){
        ans += N / 5;
        N /= 5;
    }

    cout << ans << endl;

}
