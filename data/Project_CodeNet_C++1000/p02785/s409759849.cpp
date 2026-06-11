#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,i;
  cin >> n >>k;
  
  long long int ans;
  ans=0;
  
  if(n>k){
  vector<long long int> h(n);
  for(i=0;i<n;++i)
  {
  cin >> h.at(i);
  }
  
  sort(h.begin(),h.end());
  
  for(i=0;i<n-k;++i)
  {
  ans=ans+h.at(i);
  }
  }
  cout << ans << endl;
  
return 0;
}