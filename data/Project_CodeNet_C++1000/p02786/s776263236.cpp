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

int main(){
    ll H; cin >> H;

    ll count = 0;
    while (H > 0){
        H /= 2;
        count++;
    }
    count--;
    if(count==0){
        cout << 1 << endl;
        return 0;
    }
    ll ans = 2;
    while (count > 0){
        ans *= 2;
        count--;
    }
    ans -= 1;
    cout << ans << endl;
}
