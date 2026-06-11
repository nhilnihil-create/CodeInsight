#include <stdio.h>
#include <string.h>

int main(){

	int Tc;
	scanf("%d",&Tc );
	long long int data[Tc]={}; long long int Tot=1;
	
	for (int i=0; i<Tc; i++){
		scanf("%lld", &data[i]);
	}
	
	for (int j=0; j<Tc; j++){
		if (data[j]==0){
		printf("0");
		return 0;	
		}
	}
	for(int k=0; k<Tc; k++){
		if (data[k]>1000000000000000000/Tot){
		printf ("-1");
		return 0;	
		} else {
		Tot *= data[k]; 		
		}
	
	}
	printf ("%lld", Tot);
	return 0;
}