#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar6 array<int, 6>
typedef long long LL;
const int P = 1e9+7;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

int n, d[N];
LL c[N];

int main(){
	scanf("%d",&n);
	LL ans = -1, sum = 0;
	rep(i,1,n) scanf("%d%lld",d+i,c+i), ans += c[i], sum += c[i]*d[i];
	ans += (sum-1) / 9;
	printf("%lld\n",ans);
	return 0;
}