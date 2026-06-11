#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3+5;
ll dp[maxn][maxn];
struct node{
	ll pi,val;
}p[maxn];
bool cmp(node a,node b){
	return a.val<b.val;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) {scanf("%lld",&p[i].val); p[i].pi = i;}
	sort(p+1,p+1+n,cmp);
    for(int i = 1;i<=n;i++) dp[i][i] = p[1].val*abs(i - p[1].pi);
    for(int i = 2;i<=n;i++){
    	for(int l = 1,r = i;r<=n;r++,l++){
    		dp[l][r] = max(dp[l][r],max(dp[l+1][r]+p[i].val*abs(l-p[i].pi),dp[l][r-1]+p[i].val*abs(p[i].pi - r)));
    	}
    }
    printf("%lld",dp[1][n]);
	return 0;
}