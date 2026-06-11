#pragma region header
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define ts to_string
#define all(v) (v).begin(), (v).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector <string>
#define vvs vector <vector<string>>
#define pq  priority_queue<int>
using ll = long long;
/* ----------------よく使う数字や配列----------------- */
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
const int INF = 2000000000;
const int MINF=-2000000000;
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */
/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
bool isprime(ll a)//素数判定、primeならtrue,違うならfalse
{
    if (a < 2) return false;
    else if (a == 2) return true;
    else if (a % 2 == 0) return false;
    double m = sqrt(a);
    for (int i = 3; i <= m; i += 2)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    // 素数である
    return true;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll kind(vi SYURUI) {//vector<int>型の配列の要素の種類数
    int size = SYURUI.size();
    sort(all(SYURUI));
    int cnt = 1;
    rep(i, size-1) {
        if (SYURUI[i] != SYURUI[i + 1])cnt++;
    }
    return cnt;
}
/* ----------------------end----------------------- */
#pragma endregion
signed main() {
    int N; cin >> N;
    vi W(N); rep(i, N)cin >> W[i];
    int SMALL = INF;
    int ALLSUM = 0;
    for (auto x : W)ALLSUM += x;
    for (int i = 0; i <= N; i++) {
        int sum1 = 0;
        int sum2;
        for (int j = 0; j < i; j++) {
            sum1 += W[j];
        }
        sum2 = ALLSUM - sum1;
        int ABS = abs(sum1 - sum2);
        SMALL = min(SMALL, ABS);
    }
    cout << SMALL << endl;
}

