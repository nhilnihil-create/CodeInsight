#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    int H, N; cin >> H >> N;
    vi A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }
    vector<ll> dp(H+1, LINF);
    dp[H]=0;
    for(int i=H; i>=1; i--){
        for(int j=0; j<N; j++){
            if(i+A[j] <= H){
                dp[i]=min(dp[i], dp[i+A[j]]+B[j]);
            }
        }
    }
    ll res=LINF;
    for(int i=0; i<N; i++){
        for(int j=1; j<=min(A[i], H); j++){
            res=min(res, dp[j]+B[i]);
        }
    }
    cout << res << endl;
    return 0;
}