#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

long long t[2001][2001] = {};

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<long long, int>> v(n);

    for(int i = 0; i < n; i++)
    {
        cin>>v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), greater<pair<long long, int>>());

    for(int i = 1; i <= n; i++)
        t[0][i] = -1e18;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            t[i][j] = max((t[i-1][j] + ((long long)abs(n-i+j-v[i-1].second))*v[i-1].first), (long long)(j > 0 ? (t[i-1][j-1] + ((long long)abs(j-1-v[i-1].second))*v[i-1].first) : 0));

    long long meg = 0;
    for(int i = 0; i <= n; i++)
        meg = max(meg, t[n][i]);

    cout<<meg<<"\n";

    return 0;
}
