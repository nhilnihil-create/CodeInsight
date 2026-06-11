#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  long long int arr[n], max = 1e18, prodak = 1, flag = 0, zero = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    flag = (arr[i] > max) ? 1 : flag;
    prodak = prodak * arr[i];
    (arr[i]) ? max = max/arr[i] : zero = 1; 
  }
  if (zero == 1){
  	printf("0\n");
  }
  else {
  	if (flag == 1){
  		printf("-1\n");
	  }
	  else{
	  	printf("%lld\n",prodak);
	  }
  }
  return 0;
}