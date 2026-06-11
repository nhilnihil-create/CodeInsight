#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
string S;
int dp[1000010][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    N = S.size();
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = inf;
        }
    }
    reverse(S.begin(), S.end());    
    for(int i = 0; i < N; i++){
        dp[i][0] += S[i] - '0';
        chmin(dp[i + 1][0], dp[i][0]);
        chmin(dp[i + 1][1], dp[i][0]);
        chmin(dp[i + 1][2], dp[i][0]);

        dp[i][1] += (S[i] - '0') + 2;
        chmin(dp[i + 1][0], dp[i][1]);
        chmin(dp[i + 1][1], dp[i][1]);
        chmin(dp[i + 1][2], dp[i][1]);

        dp[i][2] += ('9' - S[i]);
        chmin(dp[i + 1][1], dp[i][2]);
        chmin(dp[i + 1][2], dp[i][2]);
    }
    cout << min({dp[N - 1][0], dp[N- 1][1], dp[N][1] + 2}) << endl;
    return 0;
}