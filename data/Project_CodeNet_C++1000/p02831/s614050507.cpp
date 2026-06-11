#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
ll A, B;
ll mgcd(ll a, ll b)
{
    ll max = (a > b) ? a : b;
    ll min = (a < b) ? a : b;
    while (max % min)
    {
        ll tmp = max;
        max = min;
        min = tmp % min;
    }
    return min;
}
void func()
{
    cin >> A >> B;
    cout << A * B / mgcd(A, B) << endl;
}
int main()
{
    func();
}