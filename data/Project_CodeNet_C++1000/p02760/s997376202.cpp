#include<stdio.h>

int main(){
	int arr[12]={0};
	int a,b,c,d,e,f,g,h,i;
	scanf("%d %d %d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&g,&h,&i);
	int n;
	scanf("%d", &n);
	for(int j=1;j<=n;j++){
		int angka;
		scanf("%d", &angka);
		if(angka==a) arr[1]++;
		else if(angka==b) arr[2]++;
		else if(angka==c) arr[3]++;
		else if(angka==d) arr[4]++;
		else if(angka==e) arr[5]++;
		else if(angka==f) arr[6]++;
		else if(angka==g) arr[7]++;
		else if(angka==h) arr[8]++;
		else if(angka==i) arr[9]++;
	}
	//printf("1=%d 2=%d 3=%d 4=%d 5=%d 6=%d 7=%d 8=%d 9=%d\n", arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);
	if(arr[1]>=1&&arr[2]>=1&&arr[3]>=1){
		printf("Yes\n");
	}
	else if(arr[4]>=1&&arr[5]>=1&&arr[6]>=1){
		printf("Yes\n");
	}
	else if(arr[7]>=1&&arr[8]>=1&&arr[9]>=1){
		printf("Yes\n");
	}
	else if(arr[1]>=1&&arr[4]>=1&&arr[7]>=1){
		printf("Yes\n");
	}
	else if(arr[2]>=1&&arr[5]>=1&&arr[8]>=1){
		printf("Yes\n");
	}
	else if(arr[3]>=1&&arr[6]>=1&&arr[9]>=1){
		printf("Yes\n");
	}
	else if(arr[1]>=1&&arr[5]>=1&&arr[9]>=1){
		printf("Yes\n");
	}
	else if(arr[7]>=1&&arr[5]>=1&&arr[3]>=1){
		printf("Yes\n");
	}
	else printf("No\n");
	return 0;
}