#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a,b,c,k;

int main(void){
	scanf("%d %d %d %d",&a,&b,&c,&k);
	int ans=0;
	ans+=min(k,a);
	k-=a;
	k-=b;
	if(k>0){
		ans-=k;
	}
	printf("%d\n",ans);
	return 0;
}
