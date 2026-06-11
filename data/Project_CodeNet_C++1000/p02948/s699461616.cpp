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
    int N,M;cin >> N >> M;
    vector<P> retu(N);
    for(int i = 0;i<N;i++) cin >> retu.at(i).first >> retu.at(i).second;
    sort(retu.begin(),retu.end());
    vector<int> days(100005);
    vector<int> indexrui(100005);
    int now = retu.at(0).first;
    int ren = 1;
    for(int i = 1;i<N;i++){
        if(retu.at(i).first != now){
            days.at(now) = ren;
            now = retu.at(i).first;
            ren = 1;
        }
        else ren++;
        if(i == N-1){
            days.at(now) = ren;
        }
    }
    //何日目がどのindexから始まるかの累積和（ダルすぎ）
    for(int i = 1;i<=M;i++){
        indexrui.at(i) = indexrui.at(i-1)+days.at(i);
    }
    int ans = 0;
    priority_queue<int> Q;
    //🐄ろから見る
    for(int i = 1;i<=M;i++){
        for(int j = indexrui.at(i-1);j<indexrui.at(i);j++){
            Q.push(retu.at(j).second);
        }
        if(Q.empty()) continue;
        ans += Q.top();
        Q.pop();
    }
    cout << ans << endl;
}
