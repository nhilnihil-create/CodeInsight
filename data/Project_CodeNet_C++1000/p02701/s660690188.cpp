#include<bits/stdc++.h>
using namespace std;
#define int      long long int
int32_t main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    map<string,int>mp;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    cout<<mp.size()<<'\n';
    return 0;
}