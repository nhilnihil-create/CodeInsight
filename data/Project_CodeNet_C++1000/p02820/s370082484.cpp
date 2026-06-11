#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, K;
    vector<int> R(3);
    string T;

    cin >> N >> K;
    rep(i, 3) cin >> R.at(i);
    cin >> T;

    string S = "spr";
    ll ans = 0;

    vector<bool> reached(N, false);
    rep(i, N)
    {
        if (reached.at(i))
        {
            continue;
        }

        int cnt = 0;
        for (int j = i; j < N; j += K)
        {
            if (T.at(i) == T.at(j))
            {
                reached.at(j) = true;
                cnt++;
            }
            else
            {
                break;
            }
        }

        rep(j, 3)
        {
            if (T.at(i) == S.at(j))
            {
                ans += (cnt + 1) / 2 * R.at(j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}