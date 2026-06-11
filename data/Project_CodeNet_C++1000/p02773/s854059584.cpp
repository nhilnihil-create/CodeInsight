
#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string.h>
using namespace std;
#define pb push_back
#define all(v) v. begin(),v. end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define ll  long long
#define endl '\n'
void solve()
{
  ll n, a,m=1,b=1, c,k=0, i, j,l=1e9+7;
  string s, r, y;
  cin>>n;
  vector<string>v;
  map<string,int>hash;
  rep(i,0,n) {cin>>s;hash[s]++;}
  for(auto x:hash)
  {
    if(x.ss>k)k=x.ss;
  }
  for(auto it=hash.begin();it!=hash.end();it++)
  {
    if(it->ss==k) cout<<it->ff<<endl;
  }
  /*rep(i,0,v.size()) hash[v[i]]++;
  int max_count = 0, res = -1; 

    for (auto i : hash) { 

        if (max_count < i.second) { 

            //res = i.first; 

            max_count = i.second; 

        } 

    }
    vector<string>vec;
    for (auto i : hash) { 

        if (max_count == i.second) { */
/*r=i.first;
sort(r.begin(),r. end());
            cout<<r<<endl;*/
            /*  vec. pb(i.first);

            max_count = i.second; 

        } }
        rep(i,0,vec.size()) cout<<vec[i]<<endl;*/
    
  /*sort(all(v));
  rep(i,0,v.size())
  {
    if(v[i]==v[i+1] && i+1<v.size()) {k++;continue;}
    if(k>m) {m=k;k=0;}
  }
  k=0;
  rep(i,0,v.size())
  {
    if(v[i]==v[i+1] && i+1<v.size()) {k++;continue;}
    if(k==m) {sort(v[i].begin(),v[i].end());cout<<v[i]<<endl;}
    k=0;
  }*/
  
  /*sort(r.begin(),r. end());
  cout<<r;*/
}
int main()
{
 ios_base::sync_with_stdio(false);
  cin. tie(0);cout. tie(0);
    ll t=1;
  //cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}