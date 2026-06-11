#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, p; cin >> n >> p;
    string s; cin >> s;
    if (p == 2 || p == 5)
    {
        int d;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            d = s[i] - '0';
            if (d % p == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    long long cnt_mod[10002] = {0};
    cnt_mod[0]++;
    int d = 0, q = 10;
    for (int i = n; i > 0; i--)
    {
        d = d + q * (s[i-1] - '0');
        d = d % p;
        cnt_mod[d]++;
        q = (q * 10) % p;
    }
    long long ans = 0;
    for (long long c:cnt_mod)
        ans += c * (c - 1) / 2;
    cout << ans << endl;
    return 0;
}