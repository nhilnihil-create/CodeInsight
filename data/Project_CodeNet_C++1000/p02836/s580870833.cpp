#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin >> s;
  int ans,i,size;
  size=s.size();
  ans=0;
  
  for(i=0;i<size/2;++i)
  {
  if(s.at(i)!=s.at(size-1-i)) ans++;
  }

  cout << ans;
return 0;
}