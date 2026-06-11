#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int a,b,c,i;
  vector<char> s(4);
  
  cin >> a;
  for(i=0;i<4;++i)
  {cin >> s.at(i);}
  
  b=int(s.at(0)-'0')*100+int(s.at(2)-'0')*10+int(s.at(3)-'0');
  
  c=(a*b)/100;
  cout << c;
return 0;
}