#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

/*
int main(){
    int N, M; cin >> N >> M;
    vi a(M), b(M);
    vii c(M);
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for(int j=0; j<b[i]; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<int> cost(1<<N, 1e9);
    cost[0]=0;
    for(int i=0; i<M; i++){
        int bit=0;
        for(int j=0; j<(int)c[i].size(); j++){
            bit=bit|(1<<c[i][j]);
        }
        cost[bit]=min(cost[bit], a[i]);
    }
    for(int i=0; i<(1<<N); i++){
        for(int j=0; j<(1<<N); j++){
            int bit=i|j;
            cost[bit]=min(cost[bit], cost[i]+cost[j]);
        }
    }
    if(cost[(1<<N)-1] == 1e9) cout << -1 << endl;
    else cout << cost[(1<<N)-1] << endl;
    return 0;   
}
*/

int main(){
    int N, M; cin >> N >> M;
    vi a(M), b(M);
    vii c(M);
    vi d(M, 0);
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for(int j=0; j<b[i]; j++){
            cin >> c[i][j];
            c[i][j]--;
            d[i]=d[i] | (1<<c[i][j]);
        }
    }
    vector<vector<ll>> dp(M+1, vector<ll>(1<<N, LINF));
    dp[0][0]=0;
    for(int i=0; i<M; i++){
        for(int bit=0; bit<(1<<N); bit++){
            dp[i+1][bit]=min(dp[i+1][bit], dp[i][bit]);
            dp[i+1][(bit|d[i])]=min(dp[i+1][bit|d[i]], min(dp[i][(bit|d[i])], dp[i][bit]+a[i]));
        }
    }
    if(dp[M][(1<<N)-1] == LINF) cout << -1 << endl;
    else cout << dp[M][(1<<N)-1] << endl;
    return 0;
}