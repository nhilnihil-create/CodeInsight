#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    int N, tmp, p, q;
    unordered_map<int64_t, pair<int64_t, int64_t>> list;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        p = i + tmp, q = i - tmp;
        list[p].first++;
        list[q].second++;
    }
    int64_t ans = 0;
    for (auto x : list)
        ans += x.second.first * x.second.second;
    cout << ans;
}