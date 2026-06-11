#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using ll = long long;

///////////////////////////////////////////////////

int main()
{
    int N, K;
    std::cin >> N >> K;
    
    vi S(N+1);
    S[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        int a;
        std::cin >> a;
        S[i+1] = (S[i] + a) % K;
    }

    std::map<int, vi> bucket;
    for (int i = 0; i <= N; ++i)
    {
        int si = (S[i] - i) % K;
        if (si < 0) si += K;
        bucket[si].push_back(i);
    }

    ll ans = 0;
    for (auto p : bucket)
    {
        const vi &bk = p.second;
        int nbk = bk.size();
        for (int l = 0, r = 0; l < nbk - 1; ++l)
        {
            for (r = std::max(l+1, r); r < nbk; ++r)
            {
                if (bk[r] - bk[l] >= K) break;
            }
            ans += r - l - 1;
        }
    }
    std::cout << ans << std::endl;
}