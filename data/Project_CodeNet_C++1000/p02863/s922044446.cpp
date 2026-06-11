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

template<class T>
bool chmax(T &a, T b){
    if(a < b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N, T; cin >> N >> T;
    vi A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
    vi ids(N);
    for(int i=0; i<N; i++) ids[i]=i;
    sort(all(ids), [&](int i, int j){return A[i] < A[j];});
    ll res=0;
    vector<vector<ll>> dp(N+1, vector<ll>(T+4000, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<(T+4000); j++){
            if(j-A[ids[i]] >= 0 && j-A[ids[i]] <= T-1){
                chmax(dp[i+1][j], dp[i][j-A[ids[i]]]+B[ids[i]]);
            }
            chmax(dp[i+1][j], dp[i][j]);
            chmax(res, dp[i+1][j]);
        }
    }
    cout << res << endl;
    return 0;
}