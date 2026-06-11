#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;
int main()
{
 string s;
 cin>>s;
 int ans=0,xt=0;
 if(s[0]=='R'){xt++;}
 if(s[1]=='R'){xt++;}
 if(s[1]=='S'){ans=xt; xt=0;}
 if(s[2]=='R'){xt++; ans=max(ans,xt);}
 if(s[2]=='S'){ans=max(ans,xt); xt=0;}
 printf("%d\n",ans);
}

