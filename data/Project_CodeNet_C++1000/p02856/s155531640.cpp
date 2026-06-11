#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
typedef long long ll;
int n,m;
ll sum,ans,d,c;
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i){
		scanf("%lld%lld",&d,&c);
		sum += d*c;
		ans += c;
	}
	ans = ans - 1 + (sum - 1) / 9;
	printf("%lld\n",ans);
	return 0;
}