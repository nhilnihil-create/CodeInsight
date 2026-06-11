#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
  cin>>n;
  int arr[n];
  unordered_map<int,int>m;
  for(int i=1;i<=n-1;i++)
  {
     cin>>arr[i];
    m[arr[i]]++;
  }
//  sort(arr,arr+n);
  for(int i=1;i<=n;i++)
  {
    if(m[i])
    {
      cout<<m.find(i)->second<<endl;
    }
    else
      cout<<0<<endl;
     
    
  }
 
}
