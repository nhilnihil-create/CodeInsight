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
const long long INF = 100100100100;
const long long MOD = 1000000007;
typedef pair<long long,long long> P;

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
    return a * b / gcd(a, b);
}

int main() {
    long long N,D,A;cin >> N >> D >> A;
    vector<P> monster(N);
    vector<long long> zahyou(N);
    for(int i = 0;i<N;i++){
        cin >> monster.at(i).first >> monster.at(i).second;
        zahyou.at(i) = monster.at(i).first;
    }
    sort(monster.begin(),monster.end());
    sort(zahyou.begin(),zahyou.end());
    //どのモンスターを何回攻撃したかをimos法的に保存する
    vector<long long> attackCount(N*5,0);
    
    long long ans = 0;
    for(int i = 0;i<N;i++){
        long long needtoDestroy = 0;
        if(monster.at(i).second % A == 0) needtoDestroy = monster.at(i).second/A;
        else needtoDestroy = monster.at(i).second/A + 1;
        if(i > 0) attackCount.at(i) += attackCount.at(i-1);
        needtoDestroy -= attackCount.at(i);
        if(needtoDestroy < 0) continue;
        //計算してモンスターを、捌いていくぅ！
        long long X = monster.at(i).first;
        auto ite = upper_bound(zahyou.begin(),zahyou.end(),X + 2*D);
        long long canCombo = distance(zahyou.begin(),ite);
        attackCount.at(i) += needtoDestroy;
        attackCount.at(canCombo) -= needtoDestroy;
        ans+=needtoDestroy;
    }
    cout << ans << endl;
}
