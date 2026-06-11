#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
 
int i,c=0;
string s;
for( i=0;i<4;i++)
{
	cin>>s[i];
}
for(i=0;i<3;i++)
{
	if(s[i]==s[i+1])
     c=c+1;	
}
if(c!=0)
cout<<"Bad";
else if(c==0)
cout<<"Good";

return 0;
}