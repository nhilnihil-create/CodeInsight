#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
  cin>>n;
  int arr[n];
  vector<int>ans(n+1);
  map<int,int>m;
  for(int i=1;i<=n-1;i++)
  {
     cin>>arr[i];
   ans[arr[i]]++;
  }

    for(int i=1;i<=n;i++)
  {
    cout<<ans[i]<<endl;
     
  }
 
}
