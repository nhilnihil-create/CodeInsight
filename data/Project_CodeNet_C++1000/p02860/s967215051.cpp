#include <stdio.h>
int main (){
	int n, jumlahangka = 0;
	scanf ("%d", &n);
	char str[102];
	scanf ("%s", &str);
	for (int i=0;i< n/2;i++){
	if (str[i] == str[i + n/2]){
	
	jumlahangka++;
			
		}
		
	}
	if (n % 2 == 1) {
		printf("No");
		return 0;
	}

	
	jumlahangka == n/2 ? printf ("Yes\n") : printf ("No\n");
return 0;
}