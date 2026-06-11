#include<bits/stdc++.h>
#define pie 3.141592653589
using namespace std;

int main()
{
  long long N,ans=1000000000000;scanf("%lld",&N);
  long long i=0;
  while((i+1)*(i+1)<=N)
  {
    i++;
    if(N%i!=0)continue;
    long long j=N/i;
    ans=min(i+j-2,ans);
  }
  printf("%lld",ans);
}