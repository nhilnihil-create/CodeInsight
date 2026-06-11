#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};


int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> dp(1 << 12, INF);
    dp[0] = 0;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        int key = 0;
        rep(j, b){
            int c;
            cin >> c;
            key = key | 1 << (c-1);
        }
        rep(x, 1<<N){
            if(dp[x|key] > dp[x] + a) dp[x|key] = dp[x] + a;
        }
    }
    if(dp[(1 << N) - 1] == INF) dp[(1 << N) - 1] = -1;
    cout << dp[(1 << N)- 1] << endl;
}