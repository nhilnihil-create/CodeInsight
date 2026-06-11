#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
string s;
for(int i=0;i<4;i++)
{
cin>>s[i];
}

 if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3])
printf("Yes\n");
else if(s[0] == s[2] && s[2] != s[1] && s[1] == s[3])
printf("Yes\n");
else if(s[0] == s[3] && s[3] != s[1] && s[1] == s[2])
printf("Yes\n");
else
 printf("No\n");

return 0;
}