#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout << (x ? "Yes" : "No") << endl;
#define out(s) cout << s << endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(), s.end()
void vout(vi v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;
}
long long int gcd(long long int x, long long int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    lli k, ans = 0;
    cin >> k;
    rep(i, k) rep(j, k) rep(l, k)
    {
        ans += gcd(i+1, gcd(j+1, l+1));
    }
    out(ans);
}