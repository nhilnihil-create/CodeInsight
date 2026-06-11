#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool cmp(pair<string,int>p1,pair<string,int>p2)
{
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }

}
int main()
{
    int n,ma=0;
    string s;
    cin>>n;
    map<string,int>mp;
    while(n--)
    {
        cin>>s;
        mp[s]++;
    }
    vector<pair<string,int>>v;
    for(auto i:mp)
    {
        ma=max(ma,i.second);

    }
    for(auto i:mp)
    {
        if(i.second==ma)
        {
            v.push_back(make_pair(i.first,i.second));
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i:v)
    {
        cout<<i.first<<endl;
    }

    return 0;
}
