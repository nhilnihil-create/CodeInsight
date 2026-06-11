#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>

#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
int main()
{

    int a, b, m;
    cin >> a >> b >> m;
    vector<int> x(a), y(b);
    vector<pair<pair<int, int>, int>> z;
    ll ans = 1001001000;
    rep(i, a) { cin >> x[i]; }
    rep(i, b) { cin >> y[i]; }
    int q, w, e;
    rep(i, m)
    {
        cin >> q >> w >> e;
        z.push_back(pair<pair<int, int>, int>(pair<int, int>(q,w),e));
#ifdef dbg
	cout<<"dbg z:"<<z[i].first.first<<' '<<z[i].first.second
		<<' '<<z[i].second<<endl;
#endif
    }

    ll tmp;
    rep(i, m)
    {
        tmp = x[z[i].first.first - 1] + y[z[i].first.second - 1] - z[i].second;
#ifdef dbg
	cout<<"tmp "<<tmp<<endl;
#endif
        ans = min(tmp, ans);
    }
 sort(x.begin(),x.end());
sort(y.begin(),y.end())
	;tmp=x[0]+y[0];
ans=min(ans,tmp);
    cout << ans << endl;
    return 0;
}

/*author  https://qiita.com/drken/items/0c88a37eec520f82b788*/
ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


std::vector<unsigned ll> genprimevec(const unsigned ll N)
{
    std::vector<bool> is_prime(N + 1);
    for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
    std::vector<unsigned ll> P;
    for (unsigned ll i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
            P.emplace_back(i);
        }
    }
    return P;
}
