#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

void dfs(string s, ll num, ll N) {
    if (s.length() == N) {
        PRINT(s);
        return;
    }
    REP(i, num+1) {
        char c = 'a' + i;
        string tmp = s + c;
        if (i == num) dfs(tmp, num+1, N);
        else dfs(tmp, num, N);
    }
    return;
}

int main()
{
    ll N;
    cin >> N;
    dfs("a", 1, N);
    return 0;
}
