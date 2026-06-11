#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;

#define forn(i, a, n) for (int i = (a); i < (int)n; i++)
#define trav(x, arr) for (auto &x : arr)
#define sz(x) (int)x.size()
#define Matrix(m, h, w) = std::vector<vector<int>> m(h, vector<int> (w)); 
using ll = long long;

#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>

// benq
const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 100001;


int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);


    int a, b, c; cin >> a >> b >> c;

    if (a == b && a != c) cout << "Yes";
    else if (a == c && a != b) cout << "Yes";
    else if (b == c && b != a) cout << "Yes";
    else cout << "No";

    return 0;
}