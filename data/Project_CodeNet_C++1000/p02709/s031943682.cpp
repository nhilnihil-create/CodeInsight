/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    WRITER:kakitamasziru/OxOmisosiru
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#define _GLIBCXX_DEBUG
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
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100100;
const int MOD = 1000000007;
typedef pair<long long,long long> P;
//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

//dp[i][j]:i個目において、i個を左詰めしたときの幸福度の最大値を表す
long long dp[2002][2002];

int main() {
    int N;cin >> N;
    vector<int> retu(N);
    for(int i = 0;i<N;i++) cin >> retu.at(i);
    vector<P> num(N);
    //first:活発度,second:位置
    for(int i = 0;i<N;i++){
        num.at(i).first = retu.at(i);
        num.at(i).second = i;
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    for(int i = 0;i<2002;i++)for(int j = 0;j<2002;j++)dp[i][j] = 0;

    //活発度が大きい順に右か左かを選択する
    //↑活発度が大きいのが端に移動するのが良いため
    for(int i = 0;i<N;i++){
        //i個目までに左詰めされた要素が何個あるか
        for(int left = 0;left <= i;left++){
            int right = i - left;
            //その要素を左に詰める
            chmax(dp[i+1][left+1],dp[i][left]+(long long)num.at(i).first*(num.at(i).second-left));
            //右に詰める
            chmax(dp[i+1][left],dp[i][left]+(long long)num.at(i).first*((N-right-1)-num.at(i).second));
        }
    }

    long long ans = 0;
    for(int i = 0;i<=N;i++){
        ans = max(ans,dp[N][i]);
    }

    cout << ans << endl;


    // PLEASE GIVE ME THE "ACCEPTED" !
}