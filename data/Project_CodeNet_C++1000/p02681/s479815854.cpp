#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
int main(){
	scanf("%s %s",s1,s2);
	bool sw  =1;
	for(int i = 0; i < strlen(s1); i++)
		sw &= s1[i]==s2[i];
	if(sw)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}