#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define NUMBER 1000000007
ll N, A, B;
ll squaring(ll x, ll n)
{
    if (n == 1)
        return x % NUMBER;
    if (n % 2 == 0)
    {
        ll t = squaring(x, n / 2);
        return (t * t) % NUMBER;
    }
    else
    {
        return (x * squaring(x, n - 1)) % NUMBER;
    }
}
void func()
{
    cin >> N >> A >> B;
    if (N == 2)
    {
        cout << '0' << endl;
        return;
    }
    ll max = squaring(2, N) - 1, tmp1(1), tmp2(1);
    // cout << max << endl;
    for (int i = 1; i <= A; ++i)
    {
        tmp1 *= (((N - i + 1) * squaring(A - i + 1, NUMBER - 2)) % NUMBER);
        tmp1 %= NUMBER;
    }
    for (int i = 1; i <= B; ++i)
    {
        tmp2 *= (((N - i + 1) * squaring(B - i + 1, NUMBER - 2)) % NUMBER);
        tmp2 %= NUMBER;
    }
    max -= (tmp1 + tmp2);
    while (max < 0)
        max += NUMBER;
    cout << max << endl;
}
int main()
{
    func();
}