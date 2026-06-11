#include <stdio.h>

int main (){
int rangeA, rangeB, kelipatan;
int jumlah = 0;
scanf("%d %d %d", &rangeA, &rangeB, &kelipatan);

for(int i=rangeA; i<=rangeB; i++){
	if(i%kelipatan==0){
		jumlah++;
	}

}
	printf("%d\n", jumlah);
	
	return 0;
}