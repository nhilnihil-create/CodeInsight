#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    vector<int64_t> s(N + 1);
    s.at(0) = 0;
    for (int i = 0; i < N; i++)
    {
        s.at(i + 1) = s.at(i) + A.at(i);
    }

    int64_t res = 0;
    map<int64_t, int64_t> m;
    for (int j = 0; j < N + 1; j++)
    {
        if (j - K >= 0)
            m[(s.at(j - K) - (j - K)) % K]--;
        int64_t t = (s.at(j) - j) % K;
        res += m[t];
        m[t]++;
    }
    cout << res << endl;
    return 0;
}
