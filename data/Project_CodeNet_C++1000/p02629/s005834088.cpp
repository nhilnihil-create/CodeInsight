#include <stdio.h>
#include <string.h>

int main(){
	long long int dogs, nim;
	char name [30];
	scanf("%lld", &dogs);
	int i = 0;

	while (dogs != 0){
		dogs--;		//kurangin biar nanti ditambah 'a' jadi sesuai
		nim = dogs % 26; //modulo untuk cari sisa yang akan ditampung ke char
		name[i] = nim+'a';
		i++;
		dogs/=26;	//utk lanjut ke baris selanjutnya
	}
	for (int k=i-1; k>=0; k--){
		printf ("%c", name[k]);
	}
	return 0;
}