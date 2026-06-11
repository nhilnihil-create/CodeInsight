#include<cstdio>
#include<cstring>

int main(void){
int i,j,n,x=0,y=0;
scanf("%d",&n);
for(i=0;i<n;i++){
	char a[101],b[101];
	scanf("%s%s",a,b);
	
	for(j=0;1;j++){
		if ((a[j]=='\0')&&(b[j]!='\0')){
			y=y+3;
		}else if ((b[j]=='\0')&&(a[j]!='\0')){
			x=x+3;	
		}else if((a[j]=='\0')&&(b[j]=='\0')){
			y++;
			x++;
		}else if (a[j]-b[j]>0){
			x=x+3;
		}else if (b[j]-a[j]>0){
			y=y+3;
		};
														
		if((a[j]=='\0')||(b[j]=='\0')) break;

		if((a[j]!='\0')&&(b[j]!='\0')&&(a[j]-b[j]!=0)) break;
	};

};
printf("%d %d\n",x,y);
		
		
return 0;
}