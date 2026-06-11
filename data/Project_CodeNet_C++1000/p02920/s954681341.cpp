#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
const int intinf = numeric_limits<int>::max();

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    int N;
    cin >> N;
    vector<int> S(1 << N);
    rep(i, 1 << N) cin >> S[i];

    multiset<int, greater<int>> ms_prenatal;
    rep(i, 1 << N) ms_prenatal.insert(S[i]);
    multiset<int> ms_alive;

    auto it_max = ms_prenatal.begin();
    ms_alive.insert(*it_max);
    ms_prenatal.erase(it_max);

    rep(n, N)
    {
        multiset<int> ms_alive_next = ms_alive;
        for (int s : ms_alive)
        {
            auto it = ms_prenatal.upper_bound(s);

            if (it == ms_prenatal.end())
            {
                cout << "No" << endl;
                return;
            }
            ms_alive_next.insert(*it);
            ms_prenatal.erase(it);
        }
        ms_alive = ms_alive_next;
    }

    cout << "Yes" << endl;
}

int main()
{
    solve();
    return 0;
}