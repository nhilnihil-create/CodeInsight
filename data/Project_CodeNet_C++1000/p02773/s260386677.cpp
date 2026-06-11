#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    int n;
    cin>>n;
    string s[n];
    map<string ,int>mp;
    int mx=-1;
    for(int i=0;i<n;i++) cin>>s[i],mp[s[i]]++,mx=max(mx,mp[s[i]]);
    vector<string>v;
    for(auto x:mp){
      if(x.second==mx) v.push_back(x.first);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) cout<<v[i]<<endl;


}
