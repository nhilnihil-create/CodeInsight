#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int K,N,sub;
  vector<int> A(200000),interval(200000);

  scanf("%d %d",&K,&N);
  REPI(N)
    scanf("%d",&A[i]);
  
  REPI(N-1)
  {
    interval[i] = A[i+1] - A[i];
  }

  interval[N-1] = A[0] + K - A[N-1];
  
  sub = 0;
  
  REPI(N)
    sub = max(sub,interval[i]);

  printf("%d\n",K-sub);

  return 0;
}