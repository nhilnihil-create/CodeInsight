#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    string a[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s;
    cin >> s;
    rep(i, 0, 7)
    {
        if (a[i] == s)
        {
            cout << 7 - i << endl;
        }
    }
}
int main()
{
    func();
}