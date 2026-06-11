#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

map<string, ll> M;

int dfs(ll n, string s, map<int, int> m1)
{
    if (s.length() >= n)
        return 0;
    auto m2=m1;
    for (int i = 97; i <= 122; i++)
    {
        if (m1[i - 1] == 0)
            break;
        m2[i]++;
        char c = i;
        M[s + c]++;
        dfs(n, s + c, m2);
    }
    return 0;
}

int main()
{
    ll n;
    cin >> n;
    map<int, int> m;
    m[96]++;
    string s = "";
    dfs(n, s, m);

    for (auto m : M)
    {
        if(m.first.length()==n)cout << m.first << endl;
    }
}