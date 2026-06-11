/*  I'm a mess, I'm a loser                  */
/*  I'm a hater, I'm a user                  */
/*  I'm a mess for your love, it ain't new   */
/*  I'm obsessed, I'm embarrassed            */
/*  I don't trust no one around us           */
/*  I'm a mess for your love, it ain't new   */

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
ll mod=1000000007;


int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);


ll t=1;
//cin>>t;
while(t--)
{

ll x,y,a,b,c;
cin>>x>>y>>a>>b>>c;
ll ar[a],br[b],cr[c],i,j;

for(i=0;i<a;i++)
cin>>ar[i];

for(i=0;i<b;i++)
cin>>br[i];

for(i=0;i<c;i++)
cin>>cr[i];

sort(ar,ar+a,greater<ll>());
sort(br,br+b,greater<ll>());
sort(cr,cr+c,greater<ll>());
vector<ll>v;

for(i=0;i<x;i++)
v.push_back(ar[i]);

for(i=0;i<y;i++)
v.push_back(br[i]);

ll ans=0;
for(i=0;i<v.size();i++)
ans+=v[i];

sort(v.begin(),v.end());

ll add=0,sub=0;

for(i=0;i<min((ll)v.size(),c);i++)
{
  if(cr[i]>v[i])
   {
     add+=cr[i];
     sub+=v[i];
   }
   else
    break;
}

cout<<ans+add-sub<<endl;

}
return 0;
}















