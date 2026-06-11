#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size()
#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define forn(i, n) for (int i = 1; i <= n; i++)
#define ford(i, n) for (int i = n; i >= 0; i--)
#define REP(i, a, n) for (int i = a; i < n; i++)
#define foreach(itr, c) for (__typeof((c).begin(), (c).end()) itr = c.begin(); itr != c.end(); itr++)
#define fill(a, b) memset(a, b, sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<char> vs;
typedef vector<pi> vpi;

using namespace std;

int main()
{
    string s, t;
    int n;
    int x;
    int count = 0;
    int temp = 0;

    cin >> s >> t;

    for (int i = 0; i < s.length() - t.length() + 1; i++)
    {
        x = 0;
        temp = 0;
        for (int j = 0; j < t.length(); j++)
        {
            if (s[i + x] == t[j])
            {
                temp++;
            }
            x++;
        }
        if (count < temp)
        {
            count = temp;
        }
    }
    cout << t.length() - count;
}