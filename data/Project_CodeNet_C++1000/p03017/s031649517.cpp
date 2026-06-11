#include<cstdio>

using namespace std;

char s[200002];
int main(){
	int n,a,b,c,d;
	scanf("%d%d%d%d%d%s",&n,&a,&b,&c,&d,s+1);
	int r1=a,r2=b;
	for(;;){
		if(r1<n&&s[r1+1]!='#')r1++;
		else if(r1<n-1&&s[r1+2]!='#')r1+=2;
		else if(r2<n&&s[r2+1]!='#')r2++;
		else if(r2<n-1&&s[r2+2]!='#')r2+=2;
		else break;
	}
	if(!(c<=r1)||!(d<=r2)){
		printf("No\n");
		return 0;
	}
	if(c>d){
		bool ok=1;
		for(int i=b-1;i+1<=d;i++)
			if(i+2<=r1&&s[i]!='#'&&s[i+1]!='#'&&s[i+2]!='#')
				ok=0;
		if(ok){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	
}