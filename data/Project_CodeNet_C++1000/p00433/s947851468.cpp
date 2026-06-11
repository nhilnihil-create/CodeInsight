#include<stdio.h>
int main(void)
{
	int a,b,i,j,s,ss;
	s=0;
	for(i=0;i<4;i++){
		scanf("%d",&a);
		s+=a;
	}
	ss=0;
	for(j=0;j<4;j++){
		scanf("%d",&b);
		ss+=b;
	}
	if(s>=ss){
		printf("%d\n",s);
	}
	else if(s<ss){
		printf("%d\n",ss);
	}
	return 0;
}