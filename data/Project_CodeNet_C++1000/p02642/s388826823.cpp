#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

const int M = 1000005;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<int> cnt(M);
    for(int x : A){
        if(cnt[x] != 0){  //xのcntが既に0でない場合
            cnt[x] = 2;
            continue;
        }
        for(int i = x; i < M; i+= x) cnt[i]++; //xの倍数にチェックしていく
    }
    int ans = 0;
    for(int x : A){
        if(cnt[x] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}