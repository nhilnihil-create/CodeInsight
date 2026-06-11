#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

int main(void)
{

  while(1){
    int n;
    scanf(" %d", &n);
    if(n == 0)
      break;

    bool prime[2 * n + 1];
    for(int i = 0; i <= 2 * n; i++){
      prime[i] = true;
    }
    prime[0] = prime[1] = false;

    int count = 0;
    for(int i = 2; i <= sqrt(2 * n); i++)
      if(prime[i])
	for(int j = 0; i * (j + 2) <= 2 * n; j++)
	  prime[i * (j + 2)] = 0;

    for(int i = n+1; i <= 2 * n; i++)
      if(prime[i]){
	count++;
	//	printf("%d ", i);
      }
    //puts("");
    printf("%d\n", count);
  }
  
  return 0;
}