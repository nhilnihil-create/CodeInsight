#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    vector<char> ch(26);
    for (int i = 0; i < 26; i++)
    {
        ch[i] = 'A' + i;
    }
    int shift;
    cin >> shift;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int t = s[i] - 'A';
        s[i] = ch[(t + shift) % 26];
    }
    cout << s << "\n";
    return 0;
}