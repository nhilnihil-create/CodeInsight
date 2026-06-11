#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) 
{
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) 
    {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) 
        {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(void)
{
    long long n; cin >> n;
    int tab[100];
    int c = 1;
    int t = 1;
    for (int i = 0; i < 100; i++)
    {
        if (i == t)
        {
            c++;
            t = c * (c + 1) / 2;
        }
        tab[i] = c - 1;
    }

    long long ans = 0;
    const auto &res = prime_factorize(n);
    for (auto p: res)
    {
        ans += tab[p.second];
    }
    cout << ans << endl;
}