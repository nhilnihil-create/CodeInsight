#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    map<char, int> mci;
    mci['R'] = 0;
    mci['G'] = 1;
    mci['B'] = 2;
    int n;
    string s;
    cin >> n >> s;
    vector<int> vi(3, 0);
    REP(i, n)
    {
        vi[mci[s[i]]]++;
    }
    ll ans = (ll)vi[0] * (ll)vi[1] * (ll)vi[2];
    REP(i, n - 2)
    FOR(j, i + 1, n)
    {
        int idx = j * 2 - i;
        if (idx >= n)
            break;
        if (mci[s[i]] != mci[s[j]] && mci[s[i]] != mci[s[idx]] && mci[s[idx]] != mci[s[j]])
            ans--; 
    }
    cout << ans << endl;
}
