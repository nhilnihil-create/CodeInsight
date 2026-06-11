#include <stdio.h>

int N,K,Q,C[100100];

int main()
{
  scanf ("%d %d %d",&N,&K,&Q);
  for (int i=0;i<Q;i++){
int x; scanf("%d",&x); C[x]++;
  }
  for (int i=1;i<=N;i++){
C[i] += K-Q;
    puts(C[i]>0?"Yes":"No");
  }

return 0;
}