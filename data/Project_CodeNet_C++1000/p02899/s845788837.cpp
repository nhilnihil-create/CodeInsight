#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
vector<pair<int,int> > vc;
int x;
int i=1;
int h=n;
while(n--)
{
cin>>x;
vc.push_back({x,i});
i++;
}
sort(vc.begin(),vc.end());
for(int i=0;i<h;i++)
{
cout<<vc[i].second<<" ";
}
}