#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m = -1;
    cin >> n;
    map <string,int> mp;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s]++;
        if(m < mp[s])
            m = mp[s];
    }
    map<string, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second == m)
        {
            cout << it->first << "\n";
        }
    }
}
