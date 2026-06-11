/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#define WOULD
#define YOU
#define PLEASE
#define ACCEPT
#define MY
#define SUBMISSION
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
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
    return a * b / gcd(a, b);
}

int main() {
    int N,M;cin >> N >> M;
    string S;cin >> S;
    //-1の場合を処理
    int ren = 0;
    for(int i = 1;i<N;i++){
        if(S.at(i) == '1') ren++;
        else ren = 0;
        if(ren >= M){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<string> ans;
    //後ろから考える
    for(int i = N;i>=0;i){
        if(i == 0) break;
        //後ろから進むマスが大きいように選ぶ→最終的に進むマスが小さくなる→辞書順で小さくなる
        for(int j = M;j>=1;j--){
            if(i-j < 0) continue;
            if(S.at(i-j) == '0'){
                string now = to_string(j);
                ans.push_back(now);
                i -= j;
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0;i<ans.size();i++){
        cout << ans.at(i);
        if(i == ans.size()-1) cout << endl;
        else cout << " ";
    }
}
