#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
struct P{
	ll x,y;
};

P arr[N];
bool cmp(P a,P b){
	return atan2(a.y,a.x) < atan2(b.y,b.x);
}



int main(){
	ll n,x,y,j;
	ll MAX=0;
	scanf("%lld",&n);
	for(ll i=0;i<n;i++){
		scanf("%lld%lld",&arr[i].x,&arr[i].y);
	}
	sort(arr,arr+n,cmp);
	for(ll i=0;i<n;i++){
		x = arr[i].x, y = arr[i].y;
		j=(i+1)%n;
		MAX=max(x*x+y*y,MAX);
		while(j!=i){
			x+=arr[j].x;
			y+=arr[j].y;
			j=(j+1)%n;
			MAX=max(x*x+y*y,MAX);
		}
	}
	double ans=sqrt(MAX);
	printf("%.10lf\n",ans);	
	return 0;
}