#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N;
    int a[N + 1];
    rep(i, 1, N + 1) { cin >> a[i]; }
    int p = 1, number = 1;
    while (p < N + 1)
    {
        if (a[p] == number)
        {
            ++number;
        }
        ++p;
    }
    if (number == 1)
        cout << -1 << endl;
    else
    {
        cout << N - number + 1 << endl;
    }
}
int main()
{
    func();
}