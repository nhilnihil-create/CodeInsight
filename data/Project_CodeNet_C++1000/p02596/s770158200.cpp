#include <bits/stdc++.h>

#ifdef DEBUG
#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))

#define LOGM(msg) (cerr << (msg))

#define LOGV(vec, sep) {                                        \
    cerr << #vec << " =";                                       \
    for (const auto& v : (vec)) cerr << " " << v;               \
    cerr << (sep); }

#define LOGA(arr, N, sep) {                                     \
        cerr << #arr << " =";                                   \
        for (int i = 0; i < N; ++i) cerr << " " << (arr)[i];    \
        cerr << (sep); }

#define LOGA2(arr, N, M, sep) {                                 \
        cerr << #arr << " =\n";                                 \
        for (int i = 0; i < N; ++i) {                           \
            for (int j = 0; j < M; ++j)                         \
                cerr << (arr)[i][j] << " ";                     \
            cerr << endl;                                       \
        } cerr << (sep); }
#else
#define LOG(var, sep)
#define LOGM(msg)
#define LOGV(vec, sep)
#define LOGA(arr, N, sep)
#define LOGA2(arr, N, M, sep)
#endif

using namespace std;
using ll = long long;

const int MAX { 1000010 };

bitset<MAX> found;

int solve(int K)
{
    ll r = 0;

    for (int i = 1; i < 2*MAX; ++i)
    {
        r *= 10;
        r += 7;
        r %= K;

        if (r == 0)
            return i;

        if (found[r])
            return -1;

        found[r] = true;
    }
        
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    auto ans = solve(K);

    cout << ans << '\n';

    return 0;
}
