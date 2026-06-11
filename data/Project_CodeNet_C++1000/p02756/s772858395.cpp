#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(int N, const vector<ll>& xs)
{
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    string S;
    int Q;
    cin >> S >> Q;

    deque<char> xs(S.begin(), S.end());
    int r = 0;

    while (Q--)
    {
        int T;
        cin >> T;

        switch (T) {
        case 1:
            r = 1 - r;
            break;

        case 2:
            {
                int F;
                string s;

                cin >> F >> s;

                char c = s.front();

                if (r)
                    F = 3 - F;

                F == 1 ? xs.push_front(c) : xs.push_back(c);
            }
        }
    }

    if (r)
        reverse(xs.begin(), xs.end());

    string ans(xs.begin(), xs.end());

    cout << ans << '\n';

    return 0;
}
