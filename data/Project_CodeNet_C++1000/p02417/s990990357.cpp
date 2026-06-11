#include<cstdio>

int main(void){
char s;
int i;

int m[26]={0};
char a[26],A[26];

for(i=0;i<26;i++){
	a[i]='a'+i;
	A[i]='A'+i;
};
int c;
while(scanf("%c",&s)!=EOF){
	if ((s>=a[0])&&(s<=a[0]+25)){
		c=s-a[0];
		m[c]++;
	}else if((s>=A[0])&&(s<=A[0]+25)){
		c=s-A[0];
		m[c]++;
	};
};

for(i=0;i<26;i++){
	printf("%c : %d\n",a[i],m[i]);
};

return 0;
}