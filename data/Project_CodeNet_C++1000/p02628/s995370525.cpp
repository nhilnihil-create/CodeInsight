#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,sum=0;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
      cin>>v[i];
  }
    
 sort(v.begin(),v.end());
 for(int i=0;i<k;i++)
 {
     sum+=v[i];
 }
 
 cout<<sum<<"\n";
 return 0;
}