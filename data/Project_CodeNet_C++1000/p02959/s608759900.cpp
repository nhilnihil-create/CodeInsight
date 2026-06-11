#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int A[N+1],B[N];
  for(int i=0;i<N+1;i++)scanf("%d",&A[i]);
  for(int i=0;i<N;i++)scanf("%d",&B[i]);
  long long ans=0;
  for(int i=0;i<N;i++)
  {
    ans+=min(A[i]+A[i+1],B[i]);
    A[i+1]=min(A[i+1],max(A[i+1]+A[i]-B[i],0));
  }
  printf("%lld",ans);
}