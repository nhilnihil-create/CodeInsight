#include <cstdio>
#include <algorithm>
#define maxn 2005
#define LL long long
using namespace std;
LL dp[maxn][maxn];
struct node{
	int seq,val;
}a[maxn];
int cmp(node a,node b){
	return a.val<b.val;
}
int main(){//大的值最后放
	int i,j,len,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i].val),a[i].seq=i;
	sort(a+1,a+1+n,cmp);//按值自小到大排序
	for(i=1;i<=n;i++)dp[i][i]=(LL)a[1].val*abs(a[1].seq-i);//神奇的初始化
	for(len=2;len<=n;len++)//区间长度
		for(i=1;i+len-1<=n;i++){//左边界
			j=i+len-1;//右边界
			dp[i][j]=max(dp[i+1][j]+(LL)a[len].val*abs(a[len].seq-i),dp[i][j-1]+(LL)a[len].val*abs(a[len].seq-j));
		}
	printf("%lld\n",dp[1][n]);
	return 0;
}