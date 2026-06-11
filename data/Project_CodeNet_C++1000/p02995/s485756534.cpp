#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ms(ll a, ll N)
{
    return N / a;
}

ll solve(ll A, ll B, ll C, ll D)
{
    ll ans = B - A + 1;

    ll mmc = lcm(C, D);
    ll cs = ms(C, B) - ms(C, A - 1);
    ll ds = ms(D, B) - ms(D, A - 1);
    ll cds = ms(mmc, B) - ms(mmc, A - 1);
 
#ifdef DEBUG
    cout << "--- A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;
    cout << "--- ns = " << ans << endl;
    cout << "    cs = " << cs << endl;
    cout << "    ds = " << ds << " [1, B] = " << ms(D, B) << ", [1, A - 1] = " << ms(D, A - 1) << endl;
    cout << "    cds = " << cds << endl;
#endif

    ans = ans - cs - ds + cds;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    auto ans = solve(A, B, C, D);

    cout << ans << '\n';

    return 0;
}
