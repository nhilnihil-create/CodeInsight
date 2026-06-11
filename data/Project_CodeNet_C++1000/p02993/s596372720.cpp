#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[5];
	int flg=0,i;
	scanf("%s",s);
	for(i=0;i<4;i++){
		if(s[i]==s[i+1]){
			flg=1;
			break;
		}
	}
	if(flg==1) printf("Bad\n");
	else printf("Good\n");
	return 0;
}
