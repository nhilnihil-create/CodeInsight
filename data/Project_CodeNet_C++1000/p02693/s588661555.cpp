#include <stdio.h>
//jarak ke titik adalah kelipatan k
//a antara b
//si antara itu hrs terpenuhi
//kl terpenuhi ok, klk ga ng
//k = kelipatan
//a titik awal, b ujung
//7 
//500 600
//600/7 = 85
//85*7 = 595
//baru dicek
//4
// 5 7
//7/4 = 1
//1 *4 = 5
//kalo lebih kecil dari bates 1 jadinya false
int main(){
	int kelipatan, awal, akhir, patokan;
	
	scanf("%d", &kelipatan);
	scanf("%d %d", &awal, &akhir);
	
	patokan = akhir/kelipatan;
	
	if(patokan*kelipatan >= awal){
		printf("OK\n");
	}	else {
		printf("NG\n");
	}
	
	return 0;
}