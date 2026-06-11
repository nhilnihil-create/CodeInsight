#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N;
void func()
{
    cin >> N;
    string s;
    cin >> s;
    rep(i, 0, s.size())
    {
        if (s[i] - 'A' + N >= 26)
        {
            s[i] += (N - 26);
        }
        else
        {
            s[i] += N;
        }
    }
    cout << s << endl;
}
int main()
{
    func();
}