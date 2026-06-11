#include<stdio.h>

int main(){
	
	long long int n;
	scanf("%lld", &n);
	int i=0, temp;;
	char word[100];
	while(n>0){
		temp=0;
		temp=n%26;
		if(temp==0){
			word[i] = 'z';
			n=n/26-1;
		}
		else{
			word[i] = temp+'a'-1;
			n/=26;
		}
//		n/=26;
//		printf("%c", temp+'a'-1);
		i++;
	}
//	printf("%d", i);
	word[i]='\0';
	for(int j=i-1; j>=0; j--){
		printf("%c", word[j]);
	}
	return 0;
}