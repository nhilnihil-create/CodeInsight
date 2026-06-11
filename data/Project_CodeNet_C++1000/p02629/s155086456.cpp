#include<bits/stdc++.h>
using namespace std;
string ans;
void solve()
{
 long long N;
  cin>>N;
  ans.clear();
  string ref="zabcdefghijklmnopqrstuvwxy";
  while(N)
  { 
    int k=N%26;
    ans+=ref[k];
    if(k==0)
      N=(N/26)-1;
    else
      N=N/26;
    
  }
    reverse(ans.begin(), ans.end());
    cout<<ans;
 
  
  
}

int main()
{
solve();
}