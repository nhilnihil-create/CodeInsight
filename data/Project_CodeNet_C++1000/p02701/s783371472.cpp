#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string sh[n];
    map <string, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> sh[i];
        mp[sh[i]]++;
        if (mp[sh[i]] == 1)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}