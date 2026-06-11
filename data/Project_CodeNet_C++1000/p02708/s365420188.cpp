// finish date: 2019/6/26

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1000000007;
const long long INFll = 100000000000000000;


//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

//引き算
int sub(int a, int b) {
    return (int) (((ll) a - b + bigmod) % bigmod);
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}


//割り算(分母だけ)  -  逆元(求めたい数とbigmodを渡す)
int divide_denominator(int a, int p = bigmod, int b = -1) {
    if (b < 0) b = p - 2;  //int gyakugen(int a, int p, int b = p - 2とできなかったため。)
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        int d = divide_denominator(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, divide_denominator(a, p, b - 1));
    }
}

//割り算
int divide(int a, int b) {
    return mul(a, divide_denominator(b));
}


int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    FOR(k, K, N + 2) {
        int a = divide(mul(add(N, N - k + 1), k), 2);
        int b = divide(mul(k - 1, k), 2);
        ans = add(ans, add(sub(a, b), 1));
    }

    cout << ans << endl;
    return 0;
}
