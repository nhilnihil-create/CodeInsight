#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
#endif

  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  int sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }

  sort(a.begin(),a.end(),greater<int>());

  bool flag=1;

  double temp=sum/double(4*m);

  for(int i=0;i<m;i++)
  {
    if(a[i]<temp)
    {
      flag=0;
      break;
    }
  }


  if(!flag)
  {
    cout<<"No"<<endl;
  }
  else
  {
    cout<<"Yes"<<endl;
  }

  return 0;
}