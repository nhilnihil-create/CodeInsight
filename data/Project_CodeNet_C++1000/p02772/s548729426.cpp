#include <bits/stdc++.h>
using namespace std;

void solve(long long N, std::vector<long long> A)
{
    bool approved = true;
    for (int i = 0; (unsigned)i < A.size(); i++)
    {
        auto a = A[i];
        if (a % 2 == 0)
        {
            if (a % 3 == 0 || a % 5 == 0)
            {
                // pass
            }
            else
            {
                approved = false;
            }
        }
    }
    cout << ((approved) ? "APPROVED" : "DENIED") << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
