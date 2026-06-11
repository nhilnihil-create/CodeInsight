#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;long long mx=0;
    map<string,long long> mp;
    for(long i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]+=1;
        if(mp[s]>mx)
        {
            mx=mp[s];
        }
    }
    vector<string> v;
    for(auto x:mp)
    {
        if(x.second>=mx)
        {
            v.push_back(x.first);
        }
    }
    sort(v.begin(),v.end());
    for(long i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}