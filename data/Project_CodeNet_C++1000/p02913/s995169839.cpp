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


int main(){
    int N; cin >> N;
    string S; cin >> S;
    vii dp(N+1, vi(N+1, 0));
    int res=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(S[i] == S[j]){
                dp[i+1][j+1]=min(dp[i][j]+1, j-i);
            }
            res=max(res, dp[i+1][j+1]);
        }
    }
    cout << res << endl;
    return 0;
}