#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR_IN(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)

// 可変引数で最大公約数を求める関数
// コンパイルオプションに"-std=c++17"を追加
template <class T>
T vgcd(T m, T n) {
  return std::gcd(m, n);
}

template <class T, class... Args>
T vgcd(T a, Args... args) {
  return vgcd(a, vgcd(args...));
}

int main(void){
    int K;
    cin >> K;
    ll ans = 0;
    FOR_IN(i,1,K){
        FOR_IN(j,1,K){
            FOR_IN(k,1,K){
                ans += vgcd(i,j,k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}