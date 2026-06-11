#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

/*
左から見ていったときの最大値と右から見ていったときの最大値を比較する

*/
ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

// 1以上x以下の整数でcでもdでも割り切れないものの数を求める
ll helper(ll c, ll d, ll x)
{
    return (x - (x / c + x / d - x / lcm(c, d)));
}

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << helper(C, D, B) - helper(C, D, A - 1) << endl;
    return 0;
}