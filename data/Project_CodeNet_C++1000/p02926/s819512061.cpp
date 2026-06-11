#include<iostream>
#include<cmath> 
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;

struct node{
	ll x,y;
	
}r[1010];
bool cmp(node a,node b){
		return atan2(a.x,a.y) < atan2(b.x,b.y);//atan2：斜角计算函数 
	}
int main(){
	ll n,x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i].x>>r[i].y;
	}
	ll ans=0;
	sort(r,r+n,cmp);//只有按照极角排序之后才能保证可以达到最大的向量和是最大的。 
	for(int i=0;i<n;i++){
		x=r[i].x;
		y=r[i].y;
		ans=max(ans,x*x+y*y);
		for(int j=(i+1)%n;j!=i;j=(j+1)%n){
			x+=r[j].x;
			y+=r[j].y;
			ans=max(ans,x*x+y*y);
		}
	}
//	cout<<ans<<endl;
	double ans1=sqrt(ans);
	printf("%.13lf\n",ans1);
	return 0;
}