#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T>
T chmin(T &a, T b){
    if(a > b){ a=b; return true;}
    return false;
}

template<typename T>
T chmax(T &a, T b){
    if(a < b){ a=b; return true;}
    return false;
}

int main(){
    int H, N;
    cin >> H >> N;
    vi A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
    }

    vi dp(H+1, INF);
    dp[0]=0;
    for(int i=0; i<=H; i++){
        for(int j=0; j<N; j++){
            chmin(dp[min(i+A[j], H)], dp[i]+B[j]);
        }
    }
    cout << dp[H] << endl;
    return 0;
}