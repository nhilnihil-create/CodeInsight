#include <stdio.h>
#include <string.h>
 
int main(){
	int k;
	char str[105];
	
	scanf("%d", &k);
	getchar();
	scanf("%s", str);
	
	//subgoals
	// 1. cari panjang stringnya
	// 2. check apakah panjang string sesuai panjang maksimal
	// jika ya, langsung print stringnya
	// jika tidak, print sebanyak panjang maksimal ditambahkan 
	
	int len = strlen(str); // menampung banyak string 
	if(len <= k) {
	printf("%s\n", str);	
	} else {
		for(int i = 0; i < k; i++) {
			printf("%c", str[i]);
		}
		printf("...\n"); // ditambahkan
	}
	return 0;
}
