#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,i,j,r,g,b,remove;
  remove=0;
  r=0;
  b=0;
  g=0;
  string s;
  cin >> n >> s;
  if(n<=3) cout <<'0';
  
  else{
  for(i=0;i<n;i++)
  {
  if(s.at(i)=='R') r++;
  if(s.at(i)=='G') g++;
  if(s.at(i)=='B') b++;
  }
    
  for(i=0;i<n-1;++i)
  {
    for(j=1;2*j<=(n-1-i);++j)
   {
   if(s.at(i)!=s.at(i+j) && s.at(i)!=s.at(i+2*j) && s.at(i+j)!=s.at(i+2*j)) remove++;
   }   
  }
  cout << r*g*b-remove;
 }

return 0;}