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
    rep(i, N) P.at(i) = pair<long, long>(X.at(i) - L.at(i), X.at(i) + L.at(i));
    sort(P.begin(), P.end());

    int remove_cnt = 0;

    pair<long, long> p = P.at(0);
    for (int i = 1; i < N; i++)
    {
        if (P.at(i).first < p.second)
        {
            remove_cnt++;
            if (P.at(i).second <=p.second)
            {
                p = P.at(i);
            }
        }
        else
        {
            p = P.at(i);
        }
    }

    cout << N - remove_cnt << endl;
}
