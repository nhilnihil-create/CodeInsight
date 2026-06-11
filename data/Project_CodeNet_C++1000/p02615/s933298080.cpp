#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200010];
int n;

bool cmp(int A,int B){
	return A>B;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	int n1=n-2;ll ans=a[1];
	for (int i=2;i<=n&&n1>0;++i) {
		ans+=a[i]*min(2,n1);
		n1-=min(2,n1);
	}
	printf("%lld",ans);
	return 0;
}