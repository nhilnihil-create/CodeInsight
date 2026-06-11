#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,int>mp;
    vector<string>v1,v2;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(mp[s]==0) v1.push_back(s);
        mp[s]++;
    }
    int mx=0;
    for(int i=0;i<v1.size();i++)
    {
        mx=max(mx,mp[v1[i]]);
    }
    for(int i=0;i<v1.size();i++)
    {
        if(mp[v1[i]]==mx)
            v2.push_back(v1[i]);
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<endl;
    }

}
