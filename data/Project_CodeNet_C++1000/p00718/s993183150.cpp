#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<cstring>
using namespace std;
char cc[9];

int in(char c[]){
	int i,n,a=1,sum=0;
	n=strlen(c);
	for(i=0;i<n;i++){
		if(c[i]=='m'){
			sum+=a*1000;a=1;
		}else if(c[i]=='c'){
			sum+=a*100;a=1;
		}else if(c[i]=='x'){
			sum+=a*10;a=1;
		}else if(c[i]=='i'){
			sum+=a;a=1;
		}else{
			a=(int)(c[i]-'0');
		}
	}
	return sum;
}
void out(int c,char *cc){
	int i=0;
	if(c>=1000){
		if(c/1000==1){
			cc[i]='m';i++;c-=1000;
		}else{
			cc[i]=(char)((c/1000)+'0');i++;
			cc[i]='m';i++;
			c-=1000*(int)(cc[i-2]-'0');
		}
	}
	if(c>=100){
		if(c/100==1){
			cc[i]='c';i++;c-=100;
		}else{
			cc[i]=(char)((c/100)+'0');i++;
			cc[i]='c';i++;c-=100*(int)(cc[i-2]-'0');
		}
	}if(c>=10){
		if(c/10==1){
			cc[i]='x';i++;c-=10;
		}else{
			cc[i]=(char)((c/10)+'0');i++;
			cc[i]='x';i++;c-=10*(int)(cc[i-2]-'0');
		}
	}if(c>=1){
		if(c==1){
			cc[i]='i';
		}else{
			cc[i]=(char)(c+'0');i++;
			cc[i]='i';
		}
	}
	cout<<cc<<endl;
}
int main(){//AOJ1137
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		int a,b,c,j;
		char ca[9],cb[9];
		for(j=0;j<9;j++){cc[j]='\0';}
		cin>>ca>>cb;
		a=in(ca);
		b=in(cb);
		c=a+b;
		out(c,cc);
	}
    return 0;
}