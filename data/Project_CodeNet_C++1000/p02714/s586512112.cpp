#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    //2つ目の条件を満たすRGBの組み合わせの個数
    ll hiku = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            if (i + 2 * j >= n)
                break;
            if (s[i] != s[i + j] && s[i] != s[i + 2 * j] && s[i + j] != s[i + 2 * j])
                hiku++;
        }
    }

    ll r = 0, g = 0, b = 0;
    rep(i, n)
    {
        if (s[i] == 'R')
            r++;
        if (s[i] == 'G')
            g++;
        if (s[i] == 'B')
            b++;
    }

    cout << r * g * b - hiku << endl;
}
