#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int64_t K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    vector<int> F(N);
    for (int i = 0; i < N; i++)
    {
        cin >> F.at(i);
    }

    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    int64_t l = -1, r = 1e12;
    while (l + 1 < r)
    {
        int64_t m = (l + r) / 2;
        int64_t k = 0;
        for (int i = 0; i < N; i++)
        {
            k += max((int64_t)0, A.at(i) - m / F.at(i));
        }
        if (k <= K)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << endl;
}