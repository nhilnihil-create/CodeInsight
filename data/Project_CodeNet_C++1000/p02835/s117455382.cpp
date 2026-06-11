#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a1 + a2 + a3 >= 22)
    {
        cout << "bust\n";
    }
    else
    {
        cout << "win\n";
    }
}
int main()
{
    func();
}