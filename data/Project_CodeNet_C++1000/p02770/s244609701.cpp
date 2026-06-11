#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>
using namespace std;
#define all(x) (x).begin(), (x).end()

const int N = 500000;
const long long MOD = 1e9 + 7;

int n, q;
long long d[N];

long long s[N];

void solve(int k, int x, int m)
{
    s[0] = x;
    for (int i = 1; i < k; i++) s[i] = s[i - 1] + d[(i - 1 + n) % n];
    int r = 0;
    for (int i = 0; i + 1 < k; i++) if (s[i] % m < s[i + 1] % m) r++;
    cout << r << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < q; i++)
    {
        long long k, x, m, s = 0, ans = 0;
        cin >> k >> x >> m;
        //solve(k, x, m);
        long long K = k;
        vector<long long> w;
        for (int j = 0; j < n; j++) w.push_back(d[j] % m), s += d[j] % m;
        x = x % m;
        for (int j = 0; j < n; j++)
        {
            if (k % n == 1)
            {
                break;
            }
            k--;
            int p = x;
            x = (x + w[j]) % m;
            if (p >= x) ans++;
        }
        x = x % m;
        for (int j = 0; j < n; j++)
        {
            if (w[j] == 0)
            {
                ans += k / n;
            }
        }
        long long y = x + (k / n) * s;
        ans += y / m - x / m;
        cout << K - 1 - ans << "\n";
    }
}
