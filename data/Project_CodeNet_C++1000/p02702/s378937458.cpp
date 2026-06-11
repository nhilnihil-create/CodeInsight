#include <iostream>
#include <map>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

map <long long, long long> f;
const int mod = 2019;

int main()
{_
    f[0] = 1;
    string s; cin >> s;
    int suf = 0;
    long long multi = 1;
    long long ans = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        int d = s[i] - '0';
        suf = (suf + d * multi) % mod;
        multi = (10 * multi) % mod;
        ans += f[suf];
        f[suf]++;
    }
    cout << ans;
}