#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
const int intinf = numeric_limits<int>::max();

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{
    int N;
    cin >> N;
    vector<int> S(1 << N);
    rep(i, 1 << N) cin >> S[i];

    multiset<int, greater<int>> ms_prenatal;
    rep(i, 1 << N) ms_prenatal.insert(S[i]);
    multiset<int> ms_alive;

    int M = *max_element(S.begin(), S.end());
    ms_prenatal.erase(ms_prenatal.find(M));
    ms_alive.insert(M);
    bool is_ok = true;
    rep(n, N)
    {
        for (int s : ms_alive)
        {
            auto it = ms_prenatal.upper_bound(s);
            if (it != ms_prenatal.end())
            {
                ms_alive.insert(*it);
                ms_prenatal.erase(it);
            }
            else
            {
                is_ok = false;
                break;
            }
        }
        if (!is_ok)
            break;
    }

    cout << (is_ok ? "Yes" : "No") << endl;
}
