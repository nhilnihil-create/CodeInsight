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

    multiset<long long> s;
    s.insert(0);
    s.insert(0);
    s.insert(N + 1);
    s.insert(N + 1);
    long long ans = 0;
    long long n1, n2, m1, m2;
    for (long long i = N; i > 0; i--)
    {
        s.insert(P[i]);
        auto itr = s.find(P[i]);
        n1 = P[i];
        n1 += -*--itr - 1;
        n2 = *itr;
        n2 += -*--itr - 1;

        itr = s.find(P[i]);
        m1 = -P[i];
        m1 += *++itr - 1;
        m2 = -*itr;
        m2 += *++itr - 1;

        long long count = 0;
        count += (n2 + 1) * (m1 + 1) + (m2 + 1) * (n1 + 1);
        ans += i * count;
    }
    cout << ans << endl;
}
