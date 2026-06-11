
#include <stdio.h>
/* disini kita akan minta user input angka, yang mana 
angka tersebut bakal di tambah dan dipangkatkan 2*/
int main (){
// sebagai hasil
	int sum = 0;
// sebagai inputan
	int a;
/* disni adalah saat dimana user menginput maka inoutannya akan langsung
dijumlahkan dan dipangkatkan*/
	
	while (scanf("%d", &a) != EOF) {
		sum = a + (a * a) + (a * a *a);
	}	
/* disini kita bakal print hasil penjumlahan dan pemangkatannya*/
	 printf("%d", sum); 
	/*kita pake return 0; utk memberi tahu bahwa program yang kita buat
	sudah selesai dan bisa dijalankan*/
	return 0;
}