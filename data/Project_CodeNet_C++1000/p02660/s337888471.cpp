/*
ABC169-D
正の整数が与えられます。Nに対して、以下の操作を繰り返す。
・はじめに、以下の条件をすべて満たす正の整数zを選ぶ
　・ある素数pと正の整数eを用いて、z=p^eと表せる
　・Nがzで割り切れる
　・以前の操作で選んだどの整数とも異なる
・NをN/zに置き換える
最大で何回操作を行うことができるか。
制約
1<=N<=10^12
方針

*/

#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}


int main(){
    ll n; cin >> n;
    // 素因数分解
    vector<pair<ll, ll>> p = prime_factorize(n);
    ll ans = 0;

    rep(i,p.size()){
        int count = 0;
        // 乗数を1とする。
        //int mul = 1;
        while (p[i].second - (count+1) >= 0){
            count++;
            p[i].second -= count;
            //mul += (count+1);
        }
        ans += count;
    }

    cout << ans << endl;

}
