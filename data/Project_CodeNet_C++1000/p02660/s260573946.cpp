#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
constexpr int MX = 200005;
long long n, ans;
int main(){
	scanf("%lld", &n);
	for(long long i=2; i*i<=n; i++) if(n%i==0){
		int t=0, k=0;
		for(; n%i==0; n/=i, t++);
		for(; (k+1)*(k+2)/2 <= t; k++);
		ans += k;
	}
	if(n!=1) ans++;
	printf("%lld\n", ans);
}