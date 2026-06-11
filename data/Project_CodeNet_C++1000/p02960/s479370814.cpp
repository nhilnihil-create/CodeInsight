/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 10010010010010;
const long long MOD = 1000000007;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b ;
}
//dp[i][j]:i桁目まで見た時にあまりがjの個数
long long dp[100005][13];

int main() {
    string S;cin >> S;
    int N = S.size();
    //reverse(S.begin(),S.end());
    for(int i = 0;i<100005;i++)for(int j = 0;j<13;j++) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i = 0;i<S.size();i++){
        if(S.at(i) != '?'){
            int A = S.at(i)-'0';
            //i桁目が特定できているが、余りは13通りで考える
            for(int amari = 0;amari<13;amari++){
                dp[i+1][(amari*10+A) % 13] += dp[i][amari];
            }
        }
        else{
            //?としてあり得る0~9とそれぞれだった時のあまりを求める
            for(int j = 0;j<10;j++){
                for(int amari = 0;amari<13;amari++){
                    dp[i+1][(amari*10+j) % 13] += dp[i][amari];
                }
            }
        }
        for(int j = 0;j<13;j++) dp[i+1][j] %= MOD;
    }
    cout << dp[N][5]%MOD << endl;
}
