#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  int i,sw,l,c;
  sw=0;
  c=0;
  l=s.size();
  
  for(i=0;i<l;++i)
  {
  if(s.at(i)==s.at(l-1-i)) sw++;
  }
  if(sw==l) {c++;}
  sw=0;
  
  for(i=0;i<(l-1)/2;++i)
  {
  if(s.at(i)==s.at((l-1)/2-1-i)) sw++;
  }
  if(sw==(l-1)/2) {c++;}
  sw=0;
  
  for(i=0;i<(l-3)/2;++i)
  {
  if(s.at((l+1)/2+i)==s.at(l-1-i)) sw++;
  }
  if(sw==(l-3)/2) {c++;}
  sw=0;
  
  if(c==3) cout << "Yes";
  else cout << "No";
  
return 0;  
}