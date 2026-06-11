#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;

int main(){
    int N; 
    string S;
    cin >> N >> S;

    vector<vector<int>> dp(N+1, vector<int>(N+1,0));

    for(int i = N-1; i >= 0; i--){
        for (int j = N-1; j >=0; j--){
            if (S[i]==S[j]) dp[i][j] = dp[i+1][j+1]+1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            int tmp = min(dp[i][j], j-i);
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    
}