#include<bits/stdc++.h>
using namespace std;
int main()
{ string s;
  int n;
  cin >> n >> s;
  for(int i=0;i<s.size();++i)
  {
  s.at(i)=s.at(i)+n;
  if(s.at(i)>'Z') s.at(i)=s.at(i)-'Z'+'A'-1;
  cout << s.at(i);
  }
return 0; 
}