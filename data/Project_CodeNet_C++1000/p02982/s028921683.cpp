#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n,d;
cin>>n>>d;
int a[n][d];
for(int i=0;i<n;i++)
{
for(int o=0;o<d;o++)
{
cin>>a[i][o];
}
}
int res=0;
for(int i=0;i<n;i++)
{
for(int o=i+1;o<n;o++)
{
    int cnt=0;
for(int j=0;j<d;j++)
{
cnt+=(a[i][j]-a[o][j])*(a[i][j]-a[o][j]);
}
int h=sqrt(cnt);
if(h*h==cnt)
{
res++;
}
}
}
cout<<res<<endl;
}