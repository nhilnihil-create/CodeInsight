/*
h s, d't skp th si tll i's sved
 * ABC141 E
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int sq(int n)
{
return n*n;
}
int main()
{
std::cout << std::setprecision(7);
int n;
cin>>n;
vector<pair<int,int> > vc;
int x,y;
for(int i=0;i<n;i++)
{
cin>>x>>y;
vc.push_back({x,y});
}
vector<int> arr;
int fac=1;
for(int i=1;i<=n;i++)
{
arr.push_back(i);
fac*=i;
}
double ans=0;
do
{
for(int i=1;i<n;i++)
{
ans+=(double)sqrt(sq(vc[arr[i]-1].first-vc[arr[i-1]-1].first)+sq(vc[arr[i]-1].second-vc[arr[i-1]-1].second));
}
}while(next_permutation(arr.begin(),arr.end()));
ans=(double)ans/fac;
cout<<ans;
}