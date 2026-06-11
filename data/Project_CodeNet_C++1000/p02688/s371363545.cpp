#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++)
    {
        int d;
        cin >> d;
        int r;
        for (int i = 0; i < d; i++)
        {
            cin >> r;
            mp[r].push_back(d);
        }
    }
    cout << n - mp.size();
}