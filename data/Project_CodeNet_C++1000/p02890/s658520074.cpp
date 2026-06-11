#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,a,c[300010],k,q[300010];
bool judge(int samp){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(c[mid]<samp&&(mid==n||c[mid+1]>=samp)){ans=mid;break;}
		else if(c[mid]<samp) l=mid+1;
		else r=mid-1;
	}
	if((n-ans)*samp+q[ans]>=k*samp) return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a),c[a]++;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+c[i];
	int x=n;
	for(k=1;k<=n;k++){
		while(x>=0&&!judge(x)) x--;
		printf("%d\n",x);
	}
}