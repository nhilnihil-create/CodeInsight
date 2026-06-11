#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M (1000000007)
#define N (110)
struct data{
	int x,y;
}a[N];
int n,nx[N];
ll ans;

bool cmp(data o1,data o2){
	return atan2(o1.y,o1.x)<atan2(o2.y,o2.x);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;++i) nx[i]=i+1; nx[n]=1;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;++i){
		ll x=a[i].x,y=a[i].y;
		ans=max(ans,x*x+y*y);
		for (int j=nx[i];j!=i;j=nx[j]){
			x+=a[j].x,y+=a[j].y;
			ans=max(ans,x*x+y*y);
		}
	}
	printf("%.10lf",sqrt(ans));
}
/*
将这n个二元组看做n个向量。
移动方式遵循平行四边形定则。
所以两个向量夹角越小，相加形成的和向量模长就越大。
所以将这些向量按照极角排序。
选择的向量肯定是一个区间。
枚举左右端点，求最大值即可。
*/