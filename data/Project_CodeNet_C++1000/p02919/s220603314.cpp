#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<long long> P(N + 1, 0);
    for (long long i = 1; i <= N; i++)
    {
        long long p;
        cin >> p;
        P[p] = i;
    }

    set<long long> s;
    long long ans = 0;
    for (long long i = N; i > 0; i--)
    {
        s.insert(P[i]);
        if (s.size() < 2)
        {
            continue;
        }
        long long n1 = P[i] - 1;
        long long n2 = 0;
        long long m1 = N - P[i];
        long long m2 = 0;

        auto itr = s.find(P[i]);

        if (itr != s.begin())
        {
            itr--;
            n1 = P[i] - *itr - 1;
            n2 = *itr - 1;
            if (itr != s.begin())
            {
                n2 = *itr - *(--itr) - 1;
            }
        }

        itr = s.find(P[i]);
        if (++itr != s.end())
        {
            m1 = *itr - P[i] - 1;
            m2 = N - *itr;
            if (++itr != s.end())
            {
                m2 = *itr - *(--itr) - 1;
            }
        }

        long long count = 0;
        itr = s.find(P[i]);
        if (itr != s.begin())
        {
            count += (n2 + 1) * (m1 + 1);
        }
        if (++itr != s.end())
        {
            count += (m2 + 1) * (n1 + 1);
        }
        ans += i * count;
    }
    cout << ans << endl;
}
