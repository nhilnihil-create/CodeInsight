#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main ()
{
    int n;
    cin>>n;
    vector<pair<string,ll>>v1;
    map<string,ll>v;
    ll mx=0;
    while(n--)
    {
        string a;
        cin>>a;
        v[a]++;
        if(v[a]>mx)
            mx=v[a];
    }
    for(auto it=v.begin();it!=v.end();it++)
    {
        v1.push_back({it->first,it->second});
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i].second==mx)
        {
            cout<<v1[i].first<<endl;
        }
    }

    return 0;

}
