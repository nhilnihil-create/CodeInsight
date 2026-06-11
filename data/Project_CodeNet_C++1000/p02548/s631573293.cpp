#include<cstdio>
//#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxv = 10005;
const int inf = 1e9 + 7;
int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	ll ans=0;
	for(int i=1;i<=n-1;i++){
		b=(n-1)/i;
		ans+=b;
	} 
	printf("%lld\n",ans);
	return 0;
}
