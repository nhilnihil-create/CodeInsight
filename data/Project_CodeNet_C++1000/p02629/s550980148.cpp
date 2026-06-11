#include<bits/stdc++.h>
using namespace std;
vector<char>ans;
void solve()
{
 long long N;
  cin>>N;
  ans.clear();
  string ref="zabcdefghijklmnopqrstuvwxy";
  while(N)
  { 
    int k=N%26;
    ans.push_back(ref[k]);
    if(k==0)
      N=(N/26)-1;
    else
      N=N/26;
    
  }
  for(int i=ans.size()-1;i>=0;i--)
  {
    cout<<ans[i];
  }
  
  
  
}

int main()
{
solve();
}