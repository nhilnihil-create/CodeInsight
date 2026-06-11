#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
vector<int> vc;
int a;
for(int i=0;i<n;i++)
{
cin>>a;
vc.push_back(a);
}
sort(vc.begin(),vc.end());
int ans=0;
for(int i=0;i<n;i++)
{
for(int o=i+1;o<n;o++)
{
int k=lower_bound(vc.begin()+o+1,vc.end(),vc[i]+vc[o])-vc.begin();
ans+=max(k-o-1,0);
}
}
cout<<ans<<endl;
}
