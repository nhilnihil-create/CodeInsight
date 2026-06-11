#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i<N; i++) {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), [&](auto x, auto y) {
        return ((x.first + x.second) < (y.first + y.second));
    });
    int res = abs(v[0].first - v[N-1].first) + abs(v[0].second - v[N-1].second);
    sort(v.begin(), v.end(), [&](auto x, auto y) {
        return ((x.first - x.second) < (y.first - y.second));
    });
    res = max(res, abs(v[0].first - v[N-1].first) + abs(v[0].second - v[N-1].second));
    cout << res << '\n';
    return 0;
}