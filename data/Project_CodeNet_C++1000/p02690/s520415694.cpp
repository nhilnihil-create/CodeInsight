#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< ll >a;

void solve()
{
  for(int i=0;i<3980;i++)a.push_back((ll)pow(i,5));
  return;
}
int bs(int s,int e,ll key)
{
  int mid=(s+e)/2;
  while(s<=e)
  {
    if(a[mid]==key)return mid;
    else if(a[mid]<=key)
    {
      s=mid+1;
    }
    else e=mid-1;
    mid=(s+e)/2;
  }
  return -1;
}

int main()
{
  
  int x;
  cin>>x;
  solve();
  for(int i=0;i<3979;i++)
  {
    ll t=a[i];
    ll A=x-t;
    int k=bs(0,3979,A);
    if(k!=-1)
    {
      cout<<k<<' '<<-i<<endl;
      return 0;
    }
  }
   for(int i=0;i<3979;i++)
  {
    ll t=a[i];
    ll A=x+t;
    int k=bs(0,3979,A);
    if(k!=-1)
    {
      cout<<k<<' '<<i<<endl;
      return 0;
    }
  }
  
  return 0;
}