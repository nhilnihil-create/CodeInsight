#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
int n,p,q;
p=0;q=0;
string str1,str2;
cin>>n;

for(int i=0;i<n;i++)
{
	cin>>str1>>str2;
if(str1==str2){p++;q++;}
else if(str1<str2){q+=3;}
else if(str1>str2){p+=3;}
}
cout<<p<<" "<<q<<endl;
return 0;
}