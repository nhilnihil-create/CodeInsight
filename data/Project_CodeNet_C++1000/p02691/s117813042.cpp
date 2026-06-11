#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
int N, M;
void func()
{
    cin >> N;
    ll ans(0), A[N];
    map<ll, int> B;
    rep(i, 1, N + 1)
    {
        cin >> A[i];
        ll k = i - A[i];
        if (B.count(k))
            ++B[k];
        else
            B[k] = 1;
    }
    rep(i, 1, N + 1)
    {
        ll k = i + A[i];
        if (B.count(k))
            ans += B.find(k)->second;
    }
    cout << ans << endl;
}
int main()
{
    func();
}
