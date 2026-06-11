#include<bits/stdc++.h>
using namespace std;
char s[200100];
int main(){
	scanf("%s",s);
	int sum = 0;
	for(int i = 0; i < strlen(s); i++)
		sum += s[i] - '0';
	if(sum%9)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}