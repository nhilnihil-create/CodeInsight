#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N];int count=0;
  for(int i=0;i<N;i++)scanf("%d ",&a[i]);
  for(int i=0;i<N;i++)if(a[i]==count+1)count++;
  if(count==0)printf("-1");
  else printf("%d",N-count);
}