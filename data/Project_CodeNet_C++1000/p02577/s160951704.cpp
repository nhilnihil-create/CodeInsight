#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
string s;
cin >> s;
int ans=0;
for(int i=0;i<s.size();i++)
{
ans=ans+s[i]-'0';
}
if(ans%9==0){printf("Yes");}
else{printf("No");}
}
