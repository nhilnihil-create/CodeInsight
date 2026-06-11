#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;
#define int ll
/*
問題文

高橋王国には N個の町があります。町は 1 から Nまで番号が振られています。

それぞれの町にはテレポーターが 1
台ずつ設置されています。町 i(1≤i≤N) のテレポーターの転送先は町 Aiです。

高橋王は正の整数 Kが好きです。わがままな高橋王は、町 1 から出発してテレポーターをちょうど K回使うと、どの町に到着するかが知りたいです。

高橋王のために、これを求めるプログラムを作成してください。
*/
signed main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a; --a;
        A[i] = a;
    }

    int logK = 1;
    while ((1LL << logK) < K) logK++;

    vector<vector<int>> doubling(N, vector<int>(logK));

    for (int i = 0; i < N; i++) {
        doubling[i][0] = A[i];
    }

    for (int k = 1; k < logK; k++) {
        for (int i = 0; i < N; i++) {
            doubling[i][k] = doubling[doubling[i][k - 1]][k - 1];
        }
    }

    int now = 0;
    for (int k = 0; K > 0; k++) {
        //Note that the for loop above uses both k and K
        if (K & 1) {
            now = doubling[now][k];
        }

        K = K >> 1;
        /*シフト演算の考え方
        0b0010111011
        これを右にずらすのが>>で
        左にずらすのが<<である
        */
    }

    cout << now + 1 << endl;
}