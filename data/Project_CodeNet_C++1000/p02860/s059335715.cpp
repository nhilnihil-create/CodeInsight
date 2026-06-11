#include <stdio.h>
 
int main () {
	int n,flag = 1;
	scanf("%d", &n);//isi space array word
	char word[n];  //terisi sesuai inputan
	scanf("%s", word);

	if (n % 2 != 0) {
		flag = 0; //kalau ganjil udh pasti salah
	}
	
	for(int i = 0; i < n / 2;i++) {     				//diloop n dibagi dua agar bisa membandingkan
		if (word[i] != word[n / 2 + i]) {  				//kalau sama arraynya print yes
			flag = 0;
		    break;										// contoh n 6 maka diloop 3kali
		}
	}													//  word[0] ==  word[3] 
	flag ? puts("Yes") : puts("No");					//	word[1] ==  word[4]
														//	word[2]	==	word[5]}
	
	return 0;
}