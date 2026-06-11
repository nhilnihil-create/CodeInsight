#include<cstdio>
#include<algorithm>
#define For(i,A,B) for(i=A;i<=(B);++i)
using namespace std;
typedef long long ll;
int a[100050],n,m,v,p;
inline bool cmp(int x,int y){return x>y;}
inline bool check(int k){
	if(a[k]>=a[p])return 1;
	if(a[k]+m<a[p])return 0;
	if(p+n-k>=v)return 1;
	int i;
	ll s=0ll;
	For(i,p,k-1)s+=a[k]+m-a[i];
	return s>=(ll)(v-p-n+k)*m;
}
int main(){
	int i,l,r,mid;
	scanf("%d%d%d%d",&n,&m,&v,&p);l=p;r=n;
	For(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}