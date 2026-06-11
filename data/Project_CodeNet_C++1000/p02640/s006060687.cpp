#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int x,y;

int main(void){
	scanf("%d%d",&x,&y);
	bool flag=false;
	for(int i=0;i<=x;i++){
		if(i*2+(x-i)*4==y){
			flag=true;
		}
	}
	printf("%s\n",flag?"Yes":"No");
	return 0;
}
