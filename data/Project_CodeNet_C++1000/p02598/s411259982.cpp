#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int>all;
int a,b;



bool can(int index)
{
  int total=0;
  for(int i=0;i<a;i++)
  {
    total+=(all[i]-1)/index;
  }

  return total<=b;
}


signed main()
{
    ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    
    

   // int a,b;
    cin>>a>>b;
    
    for(int i=0;i<a;i++)
    {
      int first;
      cin>>first;
      all.push_back(first);
    }

    int lo=1,hi=1e9;

    int index=-1;
    while(lo<=hi)
    {
      int mid=(lo+hi)/2;
      if(can(mid))
      {
        hi=mid-1;
        index=mid;
      }
      else
        lo=mid+1;
    }
    cout<<index<<endl;

    //cout<<index<<endl;

   return 0;

   
}