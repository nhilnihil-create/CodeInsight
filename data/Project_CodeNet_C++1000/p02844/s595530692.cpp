#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    rep(i, 10)
    rep(j, 10)
    rep(k, 10)
    {
        vector<char> vc(3);
        vc[0] = '0' + i;
        vc[1] = '0' + j;
        vc[2] = '0' + k;
        int idx = 0;
        rep(l, s.size())
        {
            if (s[l] == vc[idx])
            {
                idx++;
                if (idx == 3)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}
