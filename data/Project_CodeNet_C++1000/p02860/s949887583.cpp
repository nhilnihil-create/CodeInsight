#include <stdio.h>
int main (){
	int n, sama = 0;
	scanf ("%d", &n);
	char str[n + 1];
	scanf ("%s", &str);
	for (int i = 0, j = n/2; i < n/2; i++, j++){
		if (str[i] == str[j]){
			sama++;
		}
	}
	if (n % 2 != 0 || sama != n/2){
		printf ("No");
	} else if (sama == n/2){
		printf ("Yes");
	}
return 0;
}