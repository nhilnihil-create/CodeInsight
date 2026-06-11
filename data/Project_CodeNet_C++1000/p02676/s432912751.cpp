#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long K, std::string S)
{
    if (S.size() <= K)
    {
        cout << S << endl;
    }
    else
    {
        for (ll i = 0; i < K; i++)
        {
            cout << S[i];
        }
        cout << "..." << endl;
    }
}

signed main()
{
    long long K;
    scanf("%lld", &K);
    std::string S;
    std::cin >> S;
    solve(K, S);
    return 0;
}
