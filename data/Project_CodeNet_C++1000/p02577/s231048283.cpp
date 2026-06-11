#include<bits/stdc++.h>
using namespace std;
char s[100000005];
int main()
{   
	scanf("%s",s);
	int len=strlen(s);
	int m,a;
	m=0;
    for (int i=0;i<len;i++)
     {
     	a=s[i]-'0';
     	m+=a;
	 }
	if (m%9==0) 
	 cout<<"Yes";
	 else 
	  cout<<"No";
return 0;
}