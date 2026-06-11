#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(time(0));

int n, a[N];

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	
	LL sum = 0, ans = 1e14, tmp = 0;
	rep(i,1,n) sum += 1ll*a[i];
	rep(i,1,n) tmp += 1ll*a[i], ans = min(ans, abs(tmp+tmp-sum));
	cout<<ans<<endl;
	return 0;
}