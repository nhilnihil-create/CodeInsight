// #define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#include <bits/stdc++.h>
//~ #include <atcoder/all>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
//~ int A = (1<<2) | (1<<3) | (1<<5) | (1<<7);
//~ for (int bit=A; ; bit=(bit-1)&A){
//~ if (!bit) break;
//~ }
int next_combination(int sub)
{
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
//~ int n=5;
//~ int k=3; // nCkの組み合わせ、ただしk=0には対応してない
//~ int bit=(1<<k)-1; // 1000 -> 0111
//~ for(; bit < (1<<n); bit=nex_combination(bit){
//~ }
bool isPrime(int a)
{
    if (a == 2)
        return true;
    if (a <= 1 || a % 2 == 0)
        return false;

    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
//~ vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
vector<int> aaa;
// index が条件を満たすかどうか
bool isOK(int index, int key)
{
    if (aaa[index] >= key)
        return true;
    else
        return false;
}
// 汎用的な二分探索のテンプレ
int binary_search(int key)
{
    int ng = -1;              //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)aaa.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//~ int v[100100];
//~ int INF = 1 << 30;
//~ vector<vector<int>> dp(310, vector<int>(310));
//~ ll dp[110][100100];
//~ vector<int> dp(100100, 0));

//~ int seen[110];
//~ int ans[110][2];
//~ ll MOD = 1e9 + 7;

vector<vector<int>> v =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

int main()
{
    int a[9];
    rep(i, 9) cin >> a[i];

    int n;
    cin >> n;

    bool exist[9];
    rep(i, 9) exist[i] = false;

    while (n--)
    {
        int b;
        cin >> b;
        rep(i, 9) if (a[i] == b) exist[i] = true;
    }

    for (auto r : v)
    {
        bool yn = true;
        for (auto e : r)
        {
            if (exist[e] == false)
                yn = false;
        }
        if (yn == true)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
