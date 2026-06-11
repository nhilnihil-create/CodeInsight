#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int>mp;
    map<string, int>:: iterator it;
    int n, maxnum = 0;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        mp[s]++;
        if(mp[s] > maxnum)
            maxnum = mp[s];
    }
    for(it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second == maxnum)
            cout<<it->first<<endl;
    }
    return 0;
}
