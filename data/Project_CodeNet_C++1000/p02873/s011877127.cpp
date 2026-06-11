#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;
  int count1,count2,i;long long ans=0;
  for(i=0;i<(int)S.size();)
  {
    count1=0,count2=0;
    while(S[i]=='<'){i++;count1++;}
    while(S[i]=='>'){i++;count2++;}
    for(int j=max(count1,count2);j>-1;j--)ans+=j;
    for(int j=min(count1,count2)-1;j>-1;j--)ans+=j;
  }
  printf("%lld",ans);
}