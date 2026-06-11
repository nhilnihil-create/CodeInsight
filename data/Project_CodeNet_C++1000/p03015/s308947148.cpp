#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll dp[100005][2];

int main(){
    string S;
    cin>>S;
    int N = S.size();
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i <= N; i++){
        if(S[i-1] == '0'){
            dp[i][0] = (dp[i-1][0] * 3)%mod;
            dp[i][1] = dp[i-1][1];
        }
        else {
            dp[i][0] = (dp[i-1][0]*3 + dp[i-1][1])%mod;
            dp[i][1] = (dp[i-1][1] * 2)%mod;
        }
    }
    cout<<(dp[N][0]+dp[N][1])%mod<<endl;
}
