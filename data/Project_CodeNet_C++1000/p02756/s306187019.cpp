#include <bits/stdc++.h>
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
typedef long long ll;

using namespace std;

const long long MOD = 1e9 + 7;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int n;
    deque<char> q;
    cin >> s >> n;
    int cta = 0, flag = 0;
    rep(i, 0, s.length()) q.push_back(s[i]);
    rep(i, 0, n)
    {
        int t;
        cin >> t;
        if (t == 1)
            cta++, flag++;
        else
        {
            int f;
            char c;
            cin >> f >> c;
            if ((f + cta) % 2 == 1)
                q.push_front(c);
            else
                q.push_back(c);
        }
    }
    int len = q.size();
    if (cta % 2 == 0)
        rep(i, 0, len) cout << q.front(), q.pop_front();
    else
        rep(i, 0, len) cout << q.back(), q.pop_back();

    cout << endl;
}