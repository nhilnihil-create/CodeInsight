#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;cin>>n;
    map<string,int>mp;
    vector<string>v;
    for(i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        mp[x]++;
    }
    int l=-1;
    for(auto x:mp)
    {
        l=max(l,x.second);
    }
    for(auto x:mp)
    {
        if(x.second==l)
        {
            cout<<x.first<<endl;
        }

    }
}
