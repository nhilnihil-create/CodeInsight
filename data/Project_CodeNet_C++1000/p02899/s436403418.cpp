
///HELLO THERE~!
///CREATED BY MD SADMAN MEHEDI SIVAN(IUT CSE[SWE'19])

#include<bits/stdc++.h>
using namespace std;

#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define READ            freopen("input.txt","r",stdin);
#define WRITE           freopen("red.txt","w",stdout);

using ll=long long;
using ull=unsigned long long;
const double pi = 2*acos(0.0);
const long long MX = 2e5+7;
 vector<ll>v;

int main()
{
   ll n;
   cin>>n;

   vector<pair<ll,ll>>v;

   for(ll i=0;i<n;i++)
   {
       ll r;
       cin>>r;
       v.push_back(make_pair(r,i+1));
   }
   sort(v.begin(),v.end());

   for(ll i=0;i<v.size();i++)
   {
       cout<<v[i].second<<" ";
   }



}
