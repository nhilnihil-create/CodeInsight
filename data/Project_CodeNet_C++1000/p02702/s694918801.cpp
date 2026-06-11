#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    string s; cin >> s;
    int n = s.size();
    vector<int> mod(n + 1, 0);
    int d = 0;
    int m10 = 1;
    for (int i = n; i > 0; i--)
    {
        d = d + m10 * (s[i-1] - '0');
        d = d % 2019;
        mod[i-1] = d;
        m10 = (m10 * 10) % 2019;
    }

    vector<int> cnt(2019, 0);
    for (int m:mod) cnt[m]++;
    int ans = 0;
    for (int c:cnt) ans += c * (c - 1) / 2;
    cout << ans << endl;
}
