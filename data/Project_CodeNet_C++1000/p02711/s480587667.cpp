#include <bits/stdc++.h>

using namespace std;

int main()
{

string s;
cin>>s;
int c=0;
for(int i=0;i<3;i++)
{
    if(s[i]=='7'){c++;}
}
if(c==0){cout<<"No";}
else {cout<<"Yes";}
      return 0;
}
