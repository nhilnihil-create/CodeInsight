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
    //"000"から"999"を格納する配列を作る
    vector<string> V(1000);
    rep(i, 1000) V[i] = "000";
    rep(i, 1000)
    {
        string tmp = to_string(i);
        rep(j, tmp.length())
        {
            V[i][2 - j] = tmp[tmp.length() - 1 - j];
        }
    }

    ll ans = 0;
    rep(i, 1000)
    {
        ll cnt = 0;
        rep(j, n)
        {
            if (V[i][cnt] == s[j])
                cnt++;
        }
        if (cnt >= 3)
            ans++;
    }

    cout << ans << endl;
}