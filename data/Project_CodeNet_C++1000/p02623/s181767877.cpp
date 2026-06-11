#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    ll t = 0;
    rep(i,M) t += B[i];      

    int j = M;
    int ans = 0;
    rep(i,N+1){          //尺取り法
        while(j > 0 && t > K){
            j--;
            t -= B[j];     //tがKを超えないようにBを減らす
        }
        if(t > K) break;
        ans = max(ans, i+j);
        if(i == N) break;
        t += A[i];
    }
    cout << ans << endl;
    return 0;
}