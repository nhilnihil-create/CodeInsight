#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=998244353;
const int N=2e5+5;



int main(){
    int N, K; cin >> N >> K;
    ll R, S, P; cin >> R >> S >> P;
    vi score(3);
    score[0]=P, score[1]=R, score[2]=S;
    string T; cin >> T;
    vi cnt(3, 0);
    vector<vector<vector<ll>>> dp(K, vector<vector<ll>>((N-1)/K+1, vector<ll>(4, 0)));
    vector<ll> end(K);
    for(int i=0; i<N; i++){
        int val;
        switch (T[i]){
            case 'r' : 
                val=0;
                break;
            case 's' :
                val=1;
                break;
            case 'p' :
                val=2;
                break;
        }
        if(i < K){
            dp[i%K][i/K][val]=score[val];
        }
        else{
            if(dp[i%K][i/K-1][val] != 0) dp[i%K][i/K][3]=dp[i%K][i/K-1][val];
            else{
                for(int j=0; j<4; j++){
                    dp[i%K][i/K][val]=max(dp[i%K][i/K][val], dp[i%K][i/K-1][j]+score[val]);
                }
            } 
        }
        end[i%K]=max(dp[i%K][i/K][val], dp[i%K][i/K][3]);
    }
    ll res=0;
    for(int i=0; i<K; i++){
        res+=end[i];
    }
    cout << res << endl;
    return 0;
}