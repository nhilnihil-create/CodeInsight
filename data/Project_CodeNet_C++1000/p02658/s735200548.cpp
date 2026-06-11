#include <stdio.h>

// note saya masih blom ngerti ini but i will try to figure it out
int main() {
  int lines;
  scanf("%d", &lines);
  long long int arr[lines]; 
  long long int big = 1e18, end = 1, flag = 0, zero = 0;
  
  for (int i = 0; i < lines; i++) {
    scanf("%lld", &arr[i]);
    flag = (arr[i] > big) ? 1 : flag;
	// arr[1] > big itu buat tau bakal jadi -1 apa hasil total kali
    end *= arr[i];
    // ini dikaliin2 terus
    (arr[i]) ? big /= arr[i] : zero = 1;
    //^ i dont ge tthis... wtf
  }

  (zero) ? puts("0") : ((flag) ? puts("-1") : printf("%lld\n", end));
  
  return 0;
}