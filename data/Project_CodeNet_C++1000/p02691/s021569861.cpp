#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<bool> primes;
const int MAXV = 1e5;

// j - i = Aj + Ai　です。
// 上記を式変形すると以下の様になります
// Ai + i = Aj - j 　

int main()
{
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    ll ans = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int p = i - list[i];
        int a = i + list[i];
        ans += m[p];
        m[a]++;
    }
    cout << ans << endl;
    return 0;
}
