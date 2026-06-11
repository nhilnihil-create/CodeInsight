#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a,b,c,d;

int main(void){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	bool flag=false;
	while(a>0 && c>0){
		if(!flag){
			c-=b;
		}else{
			a-=d;
		}
		flag=!flag;
	}
	printf("%s\n",a>0?"Yes":"No");
	return 0;
}
