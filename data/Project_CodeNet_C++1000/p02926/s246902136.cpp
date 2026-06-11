#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1100;

struct node{
	ll x,y;
}r[maxn];

bool cmp(node a,node b){
	return atan2(a.x,a.y)<atan2(b.x,b.y);
}

int main(){
	ll n,x,y;
	cin>>n;
	for(ll i=0;i<n;i++) cin>>r[i].x>>r[i].y;
	sort(r,r+n,cmp);
	ll ans=0;
	for(ll i=0;i<n;i++){
		x=r[i].x;y=r[i].y;
		ans=max(ans,x*x+y*y);
		for(ll j=(i+1)%n;j!=i;j=(j+1)%n){
			x+=r[j].x;
			y+=r[j].y;
			ans=max(ans,x*x+y*y);
		}
	}
	double Ans=sqrt(ans);
	printf("%.13lf\n",Ans);
	
	return 0;
}