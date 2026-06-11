#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, k=0 ;
    cin >> n ;
    map<string, int> mp;
    while(n--)
    {
        string s ;
        cin >> s ;
        mp[s]++;
        k=max(k,mp[s]);
    }
    for(auto l=mp.begin(); l!=mp.end(); l++)
    {
        if(l->second==k)
            cout << l->first << endl ;
    }

    return 0;
}
