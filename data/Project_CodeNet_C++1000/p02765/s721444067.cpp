#include<stdio.h>
	int main(){
		int N,R,hasil;
		
		scanf ("%d %d",&N,&R);
		if (N<10){
			hasil = 100*(10-N);
			hasil = R + hasil;
		}
		else {
			hasil= R;
		}
		printf ("%d", hasil);
	}
