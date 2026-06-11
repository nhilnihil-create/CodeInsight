#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
int N, M;
void func()
{
    cin >> N;
    ll ans(0);
    map<ll, ll> A, B;
    ll tmp;
    rep(i, 1, N + 1)
    {
        cin >> tmp;
        if (A.count(i + tmp))
            ++A[i + tmp];
        if (!(A.count(i + tmp)))
            A[i + tmp] = 1;
        if (B.count(i - tmp))
            ++B[i - tmp];
        if (!(B.count(i - tmp)))
            B[i - tmp] = 1;
    }
    for (auto i = A.begin(); i != A.end(); ++i)
    {
        if (B.count(i->first))
            ans += (i->second * B.find(i->first)->second);
    }
    cout << ans << endl;
}
int main()
{
    func();
}