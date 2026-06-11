#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
int a[N],b[N];
bool cmp(int a,int b){
	return a>b;
}
int check(int num,int n,int m,int v,int p){
	memcpy(b,a,sizeof(a));
	for(int i=num;i<=n;i++){
		if(!v) break;
		b[i]+=m;
		v--;
	}
	for(int i=1;i<=p-1;i++){
		if(!v) break;
		b[i]+=m;
		v--;
	}
	if(!v){
		if(b[p]<=b[num]) return 1;
		else return 0;
	}
	int sum=v*m;
	for(int i=p;i<num;i++){
		if(b[i]>b[num]) return 0;
		int t=b[num]-b[i];
		t=min(t,m);
		sum-=t;
		if(sum<=0) break;
	}
	if(sum<=0) return 1;else return 0;
}
void slove(){
	int n,m,v,p;
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	int l=0;int r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid,n,m,v,p)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
}
signed main(){
	slove();
	return 0;
} 