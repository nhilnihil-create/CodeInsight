#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int k;
        cin >> k;
        mp[k]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << mp[i] << endl;
    }
}