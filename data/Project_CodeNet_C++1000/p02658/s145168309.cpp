#include <stdio.h>

int main() {
 int t,zero = 0,flag = 0; //zero buat nandain 0 gak,flag buat nandain melebihi gk
 scanf("%d",&t);
 long long int n,max = 1e18,sum = 1;  //sum 1 karena dikali 1 ya satu,max 10^18
 	for(int i=0;i<t;i++){
 		scanf("%lld",&n);
 		n>max ? flag = 1 : flag; //apakah inputan melebihi max ,flag = 1 kalau iya
		 sum *= n;  //sum kalikan dengan n
		 n==0 ? zero = 1 : max /= n;  //apakah n ada yang kalau iya penanda kasih 1 kalau tidak
		 							//max sekarang menjadi max dibagi n tadi supaya max jadi n tersebut agar tar overflow
	 }
	 if(zero ==1){  //kalau o print 0
	 	puts("0");
	 }
	 else{
	 	flag==1 ? puts("-1") : printf("%lld\n",sum);  //kalau input melebhi max maka -1
	 }

  return 0;
}