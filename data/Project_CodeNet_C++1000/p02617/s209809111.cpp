#include <bits/stdc++.h>
using namespace std;

int main()
{
    // sum{L} sum{R} f(L, R)
    // == sum{L} sum{R} (# of connected components in S)
    // == sum{L} sum{R} ((# of vertex in S) - (# of edge in S))
    // == sum{L} sum{R} (# of vertex in S) - sum{L} sum{R} (# of edge in S)
    size_t N;
    cin >> N;

    size_t ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        ans += i * (N - i + 1);
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        size_t u, v;
        cin >> u >> v;
        if (u > v)
        {
            swap(u, v);
        }
        ans -= u * (N - v + 1);
    }
    cout << ans << endl;
}
