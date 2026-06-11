#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

ll x[2010];
int S;

int main(){
	x[1]=x[2]=0,x[3]=x[4]=x[5]=1;
	for(int i=6;i<2010;i++){
		x[i]=(x[i-1]+x[i-3])%mod;
	}
	scanf("%d",&S);
	printf("%d",x[S]);
	return 0;
}