#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll d;
int n;

void solve(){
	scanf("%d %lld",&n,&d);
	int res=0;
	for(int i=1;i<=n;i++){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		if(x*x+y*y<=d*d)	res++;
	}
	printf("%d\n",res);
}
int main(){
	solve();
	return 0;
}