#include <iostream>
using namespace std;
int main(){
	int tail,c1,c2;
	char str[102];
	int f[102]={0};
	char *s;
	while(1){
		tail=1;
		fgets(str,102,stdin);
		if(str[0]=='.') break;
		s=str;
 		c1=0; c2=0;
		for(;!(*s == '.');s++){
			if(*s=='(') f[tail++]=1;
			if(*s=='[') f[tail++]=2;
			if(*s==')') if(!(f[--tail]==1)) break;
			if(*s==']') if(!(f[--tail]==2)) break;
		}
		if(tail==1 && *s == '.') cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}