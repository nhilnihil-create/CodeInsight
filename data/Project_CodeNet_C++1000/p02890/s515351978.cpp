#include<bits/stdc++.h>
using namespace std;
const int maxn=300000;
int a[maxn],b[maxn],sum[maxn];
bool cmp(const int &A,const int &B){
	return A>B;
}
int chkmin(int &A,const int &B){
	if(A<=B)
	{
		return 1;
	}
	else
	{
		A = B;
		return 0;
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		scanf("%d",&a[k]);
		b[a[k]]++;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+b[i];
	for(int k=1;k<=n;k++){
		int ans=n/k;
		int left = 0,right = k-1;
		while(left<=right)
		{
			int mid = (left+right)/2;
			if(mid==0||(sum[mid]-sum[mid-1])>=(n-sum[mid])/(k-mid))
			{
				chkmin(ans,(n-sum[mid])/(k-mid));
				left = mid+1;
			}
			else
			{
				chkmin(ans,(n-sum[mid])/(k-mid));
				right = mid-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}