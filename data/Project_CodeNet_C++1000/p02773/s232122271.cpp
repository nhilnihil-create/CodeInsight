#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,c,t,y,mx;
    string s,x;
    cin>>n;
    map<string,ll>mp;
    for(i=0;i<n;i++){
        cin>>s;
        mp[s]++;
    } vector<pair<ll,string> >v;
    for(auto z:mp){
        x=z.first;
        y=z.second;
        v.push_back({y,x});
    } sort(v.begin(),v.end());
    vector<string>vec;
    mx=v[v.size()-1].first;
    for(i=v.size()-1;i>=0;i--){
      if(v[i].first!=mx ) break;
      vec.push_back(v[i].second);
    }sort(vec.begin(),vec.end());
    for(auto x:vec) cout<<x<<"\n";
}
