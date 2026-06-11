#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
int n,k;
int p[6000];
int c[6000];
cin>>n>>k;
rep(i,n)cin>>p[i];
rep(i,n)p[i]--;
rep(i,n)cin>>c[i];
ll ans=(ll)-1e18;
for(int i=0;i<n;i++)
{
int si=i;
vector<int>s;
int x=si;

ll tot=0;
while(1)
{
x=p[x];
s.push_back(x);
tot+=c[x];
if(x==si)break;
}
ll t=0;

for(int i=0;i<s.size();i++)
{
if(i+1>k)break;
t+=c[s[i]];
ll now=0;
now=t;
if(tot>0)
{
now+=tot*((k-i-1)/s.size());


}
ans=max(ans,now);

}

}


cout <<ans;
}