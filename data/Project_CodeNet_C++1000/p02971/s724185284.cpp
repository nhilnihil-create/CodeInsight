//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,i;
  cin>>n;
  int arr[n],temp[n];
  map<int ,int>m;
  int maxm=1;
  for(i=0; i<n; i++)
  {
    cin>>arr[i];
    m[arr[i]]+=1;
    maxm=max(arr[i],maxm);
    temp[i]=arr[i];
  }
  sort(temp,temp+n);
  if(m[maxm]>=2)
  {
    for(i=0; i<n; i++)
      cout<<maxm<<'\n';
  }
  else
  {
     for(i=0; i<n; i++)
     {
      if(arr[i]==maxm)
        cout<<temp[n-2]<<'\n';
      else
        cout<<temp[n-1]<<'\n';
     }
   }
  return 0;
}