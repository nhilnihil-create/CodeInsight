#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll N, M, Q;

vector<ll> A(50);
vector<ll> B(50);
vector<ll> C(50);
vector<ll> D(50);

ll solve(int digit, int upperBound, ll point, vector<ll> E)
{
    if (digit < 0)
    {
        ll tmp = 0;
        rep(i, Q)
        {
            if (E.at(B.at(i) - 1) - E.at(A.at(i) - 1) == C.at(i))
            {
                tmp += D.at(i);
            }
        }
        return max(point, tmp);
    }
    else
    {
        for (int i = 1; i <= upperBound; i++)
        {
            E.at(digit) = i;
            point = max(point, solve(digit - 1, i, point, E));
        }
    }

    return point;
}

int main()
{

    cin >> N >> M >> Q;

    rep(i, Q) cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);

    vector<ll> E(N, 1);
    ll ans = solve(N - 1, M, 0, E);

    cout << ans << endl;

    return 0;
}