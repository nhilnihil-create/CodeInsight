#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    //今回Nは奇数
    int N;
    cin >> N;
    //ダムに貯蔵されている水の量を格納
    vector<ll> a(N);
    //各山に降った雨の量を格納
    vector<ll> x(N);
    //降った雨の総量を格納
    ll sum = 0;
    rep(i, N){
        ll A;
        cin >> A;
        sum += A;
        a[i] = A;
    }

    //1-indexで偶数番目のダムの貯蔵量の和をとる
    ll elim_sum = 0;
    for(int i = 1; i <= N-2; i+=2){
        elim_sum += a[i];
    }
    //x[0]を求める
    x[0] = sum - 2*elim_sum;
    //漸化式によって、x[i]を求めていく
    for(int i = 0; i < N-1; i++){
        x[i+1] = 2 * a[i] - x[i];
    }
    rep(i, N) cout << x[i] << endl;
    return 0;
}