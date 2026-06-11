#pragma GCC target ("avx")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")

#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

const ll INF = 100'000'000'000'000'000LL;

int N, K;
ll H[300];
vector<ll> v;

ll dp[301][301][302];
ll rmq1[301][301][302], rmq2[301][301][302];

signed main(){
    cin >> N >> K;
    rep(i, N){
        cin >> H[i];
        v.pb(H[i]);
    }
    v.pb(0);
    sort(all(v));

    for(int n=N; n>=0; n--){
        for(int k=0; k<=K; k++){
            for(int i=0; i<v.size(); i++){
                if(n == N) dp[n][k][i] = v[i];
                else{
                    dp[n][k][i] = dp[n+1][k][lower_bound(all(v), H[n])-v.begin()] + abs(H[n]-v[i]);
                    if(k > 0){
                        dp[n][k][i] = min(dp[n][k][i], rmq1[n+1][k-1][i] + v[i]);
                        dp[n][k][i] = min(dp[n][k][i], rmq2[n+1][k-1][i] - v[i]);
                    }
                }
            }
            for(int i=0; i<v.size(); i++){
                rmq1[n][k][i] = min((i == 0 ? INF : rmq1[n][k][i-1]), dp[n][k][i]-v[i]);
            }
            for(int i=v.size()-1; i>=0; i--){
                rmq2[n][k][i] = min((i == v.size()-1 ? INF : rmq2[n][k][i+1]), dp[n][k][i]+v[i]);
            }
        }
    }

    cout << dp[0][K][0] / 2LL << endl;
}