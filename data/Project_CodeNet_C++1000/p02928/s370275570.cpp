#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)
 
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    //10^9 + 7を格納
    ll limit = pow(10, 9)+7;
    //今回求める整数列Bでの転倒数を記録する変数
    ll ans = 0;
    //整数列A内での転倒数を求める
    ll cnt = 0;
    rep(i, N){
        for(int j = i + 1; j < N; j++){
            if(A[i] > A[j]) cnt++;
        }
    }
    //整数列A内での転倒数にKをかけたものをansに格納
    ans = (K * cnt) % limit;
    //K個の整数列から、2つを選ぶ選び方を格納
    ll val = (K*(K-1)/2) % limit;
    //整数列A内で、大小関係（あるA[i]よりも小さい要素がいくつ存在するかを調べ、その和をとる）を取得する
    ll v = 0;
    rep(i, N){
        rep(j, N){
            if(A[i] > A[j]) v++;
        }
    }
    ans = (ans + val * v) % limit;
    cout << ans << endl;
    return 0;
}