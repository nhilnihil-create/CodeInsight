#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

ll dp[2010][2010];

int main() {
    int N,M; cin>>N>>M;
    vector<int> S(N),T(M);
    for (int i = 0; i < N; ++i) {
        cin>>S[i];
    }
    for (int i = 0; i < M; ++i) {
        cin>>T[i];
    }

    dp[0][0]=1ll;
    for (int i = 0; i <= N; ++i) {
        dp[i][0]=1ll;
    }
    for (int i = 0; i <= M; ++i) {
        dp[0][i]=1ll;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+MOD)%MOD;
            if(S[i-1]==T[j-1]) (dp[i][j]+=dp[i-1][j-1])%=MOD;

        }
    }

    cout<<dp[N][M]<<endl;

    return 0;
}
