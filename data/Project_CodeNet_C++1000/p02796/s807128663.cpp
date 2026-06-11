#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<long> X(N);
    vector<long> L(N);

    rep(i, N) cin >> X.at(i) >> L.at(i);

    vector<pair<long, long>> P(N);
    rep(i, N) P.at(i) = pair<long, long>(X.at(i) + L.at(i), X.at(i) - L.at(i));
    sort(P.begin(), P.end());

    int ans = 0;

    pair<long, long> p;

    long cur = -1000000000;
    for (int i = 0; i < N; i++)
    {
        if (cur <= P.at(i).second)
        {
            ans++;
            cur = P.at(i).first;
        }
    }

    cout << ans << endl;
}
