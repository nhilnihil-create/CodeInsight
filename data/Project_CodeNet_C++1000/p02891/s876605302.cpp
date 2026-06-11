#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, k, i, t;
    string s;
    vector<ll> ms;
    ll ans;

    cin >> s;
    scanf("%d", &k);

    n = s.size();

    t = -1;
    for (i = 0; i < n; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            ms.push_back(1);
            t++;
        }
        else {
            ms[t]++;
        }
    }

    if (t == 0) {
        printf("%lld\n", ms[0] * k / 2);
        return 0;
    }

    ans = 0;
    for (i = 1; i < t; i++) {
        ans += ms[i] / 2;
    }

    ans *= k;

    ans += ms[0] / 2 + ms[t] / 2;

    if (s[0] == s[n - 1]) {
        ans += (ms[0] + ms[t]) / 2 * (k - 1);
    }
    else {
        ans += (ms[0] / 2 + ms[t] / 2) * (k - 1);
    }

    printf("%lld\n", ans);

    return 0;
}