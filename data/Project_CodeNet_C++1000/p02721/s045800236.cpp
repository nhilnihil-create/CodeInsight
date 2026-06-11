#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<int> v1, v2;

    int cnt = 0;
    rep(i, n)
    {
        if (cnt > k)
            break;
        if (s[i] == 'o')
        {
            v1.push_back(i);
            i += c;
            cnt++;
        }
    }
    cnt = k - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt < 0)
            break;
        if (s[i] == 'o')
        {
            v2.push_back(i);
            i -= c;
            cnt--;
        }
    }
    reverse(all(v2));
    rep(i, k) if (v1[i] == v2[i]) cout << v1[i] + 1 << endl;
    return 0;
}
