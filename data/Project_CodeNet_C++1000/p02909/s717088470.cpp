#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int i;
	char a[10],s[4][10]={"Sunny","Cloudy","Rainy","Sunny"};
	scanf("%s",a);
	for(i=0;i<3;i++){
		if(strcmp(a,s[i])==0){
			printf("%s\n",s[i+1]);
		}
	}
	return 0;
}