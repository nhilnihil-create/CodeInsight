#include<stdio.h>
#include<string>
using namespace std;
string table[]={"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char str[1280];
int main(){
	int a;
	scanf("%d",&a);
	while(a--){
		scanf("%s",str);
		int renzoku=0;
		char now='0';
		for(int i=0;str[i];i++){
			if(now!=str[i]){
				if(now!='0'){
					printf("%c",table[now-'0'][(renzoku-1)%table[now-'0'].size()]);
				}
				renzoku=1;
				now=str[i];
			}else renzoku++;
		}
		printf("\n");
	}
}