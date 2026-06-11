#include <bits/stdc++.h>
using namespace std;
int main()
{
int a=0,b=0,c,d,k=0;
string s;
  cin>>c;
cin>>s;
for(int i=0;i<c;i++)
    if(s[i]=='R')
    a++;
  
for(int i=0;i<a;i++)
    if(s[i]=='W')
    b++;
cout<<b;
}
