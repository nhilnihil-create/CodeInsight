#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
int main(void)
{
    string s;
    cin >> s;
    int len = s.length();
    rep(i, 0, len)
    {
        if (i % 2 == 0 && (s[i] == 'R' || s[i] == 'U' || s[i] == 'D'))
            continue;
        else if (i % 2 == 1 && (s[i] == 'L' || s[i] == 'U' || s[i] == 'D'))
            continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}