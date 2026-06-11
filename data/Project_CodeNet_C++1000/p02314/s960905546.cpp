#include <stdio.h>
#define MAXN 50050
//coin changing problem dp
int main ()
{
  int n, m, i, j;
  long int dp[MAXN];
  
  scanf ("%d %d", &n, &m);
  for (i = 1; i <= n; i++)
    {
      dp[i] = 0;
    }
  int d[m + 1];
  for (i = 1; i <= m; i++)
    {
      scanf ("%d", &d[i]);
      dp[d[i]] = 1;
    }
  for (i = 2; i <= n; i++)
    {
      long int min = MAXN;
      if (dp[i] == 0)
	{			//cal
	//get minimal ele
	  for (j = 1; j <= m; j++)
	    {
	      if (d[j] < i)
		{
		  if (dp[i - d[j]] < min)
		    min = dp[i - d[j]];
		    
		}
	    }
	  //printf ("min:%ld,%ld\n", min,i);
	  if(min!=MAXN)  
	  dp[i] = min + 1;
	}


    }
  //for(i = 1; i<=m; i++)
  //printf ("%ld,%ld\n", dp[5*d[i]],5*d[i]);
  printf ("%ld\n", dp[n]);
  //n = 50001;printf("%d",n);
  return 0;
}