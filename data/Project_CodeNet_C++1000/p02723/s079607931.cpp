#include <cstdio>
using namespace std;
int main(){
	char str[7];
	scanf("%s",str);
	if((str[2]==str[3])&&(str[4]==str[5]))printf("Yes");
	else printf("No");
	return 0;
	}
