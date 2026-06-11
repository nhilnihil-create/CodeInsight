#include<bits/stdc++.h>
using namespace std;

int  main()
{
string a;
cin>>a;
int cnt=0,mxcnt=0;
for(unsigned int i=0;i<a.size();i++)
{
if(a[i]=='R')
cnt++;
else
{
mxcnt=max(mxcnt,cnt);
cnt=0;
}
}
mxcnt=max(mxcnt,cnt);
cout<<mxcnt;
return 0;
}