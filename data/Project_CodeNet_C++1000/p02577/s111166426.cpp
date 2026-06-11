#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char a[200010];
int main()
{
	scanf("%s",&a);
	int sum = 0;
	int len = strlen(a);
	for(int i = 0;i < len;i++){
		sum += (a[i] - '0');
	}
	if(sum % 9 == 0) printf("Yes\n");
	else printf("No\n");
	//printf("%d\n",sum);
	return 0;
}