#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
using namespace std;
const int INF = 1e18;
const int MOD = 1000000007;

using Graph = vector<vector<int>>;
Graph G;
int wage[100];

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int A[n + 1], B[n];
    rep(i, n + 1) cin >> A[i];
    rep(i, n) cin >> B[i];

    int before = 0;
    rep(i, n + 1) before += A[i];

    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
    {
        left = min(A[i], B[i]);
        A[i] -= left;
        B[i] -= left;
        right = min(A[i + 1], B[i]);
        A[i + 1] -= right;
        B[i] -= right;
    }

    int after = 0;
    rep(i, n + 1) after += A[i];

    cout << before - after << endl;
}

signed main()
{
    solve();
    return 0;
}