#include <bits/stdc++.h>
using namespace std;
typedef unsigned int INT;
typedef unsigned long long LONG;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define FW freopen("data2.txt", "w", stdout);
//快速读入输出，只适用于整数，使用时流同步打开，C语言不准关流
// getchar()<<cin(关流)<<scanf()<<cin
template <class T>
inline bool Read(T& ret)
{
    char c;
    int sgn;
    if (static_cast<void>(c = getchar()), c == EOF)
        return 0;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (static_cast<void>(c = getchar()), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
//输出只能用于整数
template <class T>
inline void Write(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        Write(x / 10);
    putchar(x % 10 + '0');
}

void slove(int question_num)
{
    LL x, y, k;
    cin >> x >> y >> k;
    cout << (k * y + k) / (x - 1) + k << endl;
}

void slove1(int quetion_num)
{
    string s, t;
    int ans = 999999;
    cin >> s >> t;
    for (int i = 0; i < s.size() - t.size(); ++i) {
        int cur = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (t[j] != s[i + j])
                cur++;
        }
        ans = min(ans, cur);
    }
    if (s.size() == t.size()) {
        int cur = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != t[i])
                cur++;
        ans = min(ans, cur);
    }
    cout << ans << endl;
}
int main()
{
    int num = 1;
    // cin >> num;
    for (int i = 1; i <= num; ++i) {
        slove1(i);
    }
    // system("pause");
    return 0;
}