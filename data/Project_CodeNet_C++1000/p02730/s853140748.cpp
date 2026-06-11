#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
template <class T>

inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;
int cnt = 0;
bool kaibun(string str)
{
    bool flag = true;
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    string s;
    cin >> s;
    string s1 = s.substr(0, s.length() / 2);
    string s2;
    if (s.length() % 2 == 0)
    {
        s2 = s.substr(s.length() / 2, s.length() / 2);
    }
    else
    {
        s2 = s.substr(s.length() / 2 + 1, s.length() / 2);
    }
    if (kaibun(s) && kaibun(s1) && kaibun(s2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
