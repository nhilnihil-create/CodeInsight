/*
h s, d't skp th si tll i's svedclTabCtrl
 * ABC141 E
 * ABC145 D
 * ABC147 F
 * ABC174 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,k;
cin>>n>>k;
ll p[n];
ll c[n];
for(ll i=0;i<n;i++)
{
cin>>p[i];
}
for(ll i=0;i<n;i++)
{
cin>>c[i];
}
vector< vector<ll> > vc;
vector<set<ll> > st;
map<ll,ll> mp;
bool ok[n+1]={};
for(ll i=0;i<n;i++)
{
if(!ok[p[i]])
{
ll sm=0;
ll j=p[i];
vector<ll> arr;
set<ll> stt;
ll cnt=1;
arr.push_back(0);
ll ps=i;
while(!ok[j])
{
sm+=c[ps];
arr.push_back(sm);
stt.insert(j);
mp[j]=cnt;
cnt++;
ok[j]=1;
ps=j-1;
j=p[j-1];
}
vc.push_back(arr);
st.push_back(stt);
}
}
ll res=-1e19;
ll u=k;
for(ll i=1;i<=n;i++)
{
for(ll o=0;o<st.size();o++)
{
k=u;
if(st[o].count(i))
{
ll pp=mp[i];
ll ans=-1e19;

ll maxi=-1e18;
for(ll w=1;w<vc[o].size();w++)
{
maxi=max(maxi,vc[o][w]);
}

if(k>=vc[o].size()-pp)
{
for(ll j=pp;j<vc[o].size();j++)
{
ans=max(ans,vc[o][j]-vc[o][pp-1]);
}
ll kk=vc[o][vc[o].size()-1]-vc[o][pp-1];
ll ff=k-(vc[o].size()-pp);
for(ll j=1;j<=min((ll)vc[o].size()-1,ff);j++)
{
ans=max(ans,kk+vc[o][j]);
}
ll gg=0;
gg+=vc[o][vc[o].size()-1]-vc[o][pp-1];
k-=(vc[o].size()-pp);
ll f=k/(vc[o].size()-1);
gg+=vc[o][vc[o].size()-1]*f;
k%=(vc[o].size()-1);
ll nn=-1e18;
for(ll w=1;w<=k;w++)
{
nn=max(nn,vc[o][w]);
}
if(nn!=-1e18)
{
gg+=nn;
}
ans=max(ans,gg);




k=u;
gg=0;
gg+=vc[o][vc[o].size()-1]-vc[o][pp-1];
k-=(vc[o].size()-pp);
f=k/(vc[o].size()-1);
f--;
if(f>=0)
{
gg+=vc[o][vc[o].size()-1]*f;
if(nn!=-1e18)
{
gg+=maxi;
}
ans=max(ans,gg);
}


k=u;

}
else
{
for(ll j=pp;j<pp+k;j++)
{
ans=max(ans,vc[o][j]-vc[o][pp-1]);
}
}
res=max(res,ans);
break;
}
}
}

cout<<res<<endl;
}

/*
 *||||

 */
