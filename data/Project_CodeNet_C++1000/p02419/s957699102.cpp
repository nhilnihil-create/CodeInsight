#include<cstdio>
#include<cstring>

int main(void){
int i,j;

char w[11];
scanf("%s",w);
char e[]="END_OF_TEXT";
char s[1024][1024];
int n=-1;
do{
	n++;
	scanf("%s",s[n]);
}while(strcmp(s[n],e)!=0);
i=0;
while(w[i]!='\0'){
	if((w[i]>='A')&&(w[i]<='A'+25)){
		w[i]=w[i]+'a'-'A';
	};
	i++;
};

for(i=0;i<n+1;i++){
	j=0;
	while(s[i][j]!='\0'){
		if((s[i][j]>='A')&&(s[i][j]<='A'+25)){
			s[i][j]=s[i][j]+'a'-'A';
		};
		j++;
	};
};

int c=0;
for(i=0;i<n+1;i++){
	if(strcmp(s[i],w)==0){
		c++;
	};
};
printf("%d\n",c);

return 0;
}