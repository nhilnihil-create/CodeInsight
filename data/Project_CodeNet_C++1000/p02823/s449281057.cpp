#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long N,N1,A,B,ans;scanf("%lld %lld %lld",&N,&A,&B);
  if((B-A)%2==0){ans=abs(B-A)/2;printf("%lld",ans);return 0;}
  N1=min(N-B,A-1);ans=N1;
  if(N-B>A-1)
  {
    ans=A;
    B=B-A+1;A=1;
    printf("%lld",ans+(B-A)/2);
  }
  else
  {
    ans=N-B+1;
    A=A+N-B+1;B=N;
    printf("%lld\n",ans+(B-A)/2);
  }
}