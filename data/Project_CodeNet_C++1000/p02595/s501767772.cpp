#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, D;
typedef pair<int, int> field_xy;

int main()
{
    cin >> N >> D;
    field_xy xy[N];
    for (int i = 0; i < N; i++)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (pow(xy[i].first, 2) + pow(xy[i].second, 2) <= pow(D, 2))
            count++;
    }

    cout << count << endl;
}
