#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 300005
#define LL long long
int a[N],b[N],T[N];LL ans[N],sum;
int main()
{
	int n,i,j,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	sort(b+1,b+n+1);
	for(t=1,j=1;t<=n;t++){
		while(j<=n&&b[j]<=t){
			sum+=1ll*b[j];
			j++;
		}
		ans[t]=sum+1ll*(n-j+1)*t;
	}
	for(t=1,i=n;i>=1;i--){
		while(t<=n&&ans[t]>=t*i)
			t++;
		T[i]=t-1;
	}
	for(i=1;i<=n;i++)
		printf("%d\n",T[i]);
}