#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int N;
vector < pair <int, int> > v;

long double maxAns;

inline bool cmp(const pair <int, int> A, const pair <int, int> B)
{
    return atan2(A.second, A.first) < atan2(B.second, B.first);
}

int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < N; i++)
        v.push_back(v[i]);

    for(int start = 0; start < N; start++)
    {
        long long x = 0LL, y = 0LL;

        for(int l = 1; l <= N; l++)
        {
            x += 1LL * v[start + l - 1].first;
            y += 1LL * v[start + l - 1].second;

            maxAns = max(maxAns, sqrtl(1LL * x * x + y * y));
        }
    }

    cout << fixed << setprecision(60) << maxAns << '\n';
    return 0;
}
