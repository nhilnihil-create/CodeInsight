//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(int temp[], int a[], int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    //cout<<temp[i]<<" "<<a[i]<<'\n';
    if(temp[i]!=a[i])
      return false;
  }
  return true;
}
int main()
{   
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,i;
  cin>>n;
  int a[n], b[n];
  int temp[n];
  for(i=0; i<n; i++)
    temp[i]=i+1;

  for(i=0; i<n; i++)
    cin>>a[i];

  for(i=0; i<n; i++)
    cin>>b[i];

  int cnt1=0,cnt2=0;
  bool chk;
  while(1)
  {
    cnt1++;
    chk=check(temp,a,n);
    if(chk==true)
      break;
    else
      next_permutation(temp,temp+n);
  }

  //cout<<cnt1;

  for(i=0; i<n; i++)
    temp[i]=i+1;

  while(1)
  {
    cnt2++;
    chk=check(temp,b,n);
    if(chk==true)
      break;
    else
      next_permutation(temp,temp+n);
  }
  int ans=abs(cnt1-cnt2);
  cout<<ans;

  return 0;
}