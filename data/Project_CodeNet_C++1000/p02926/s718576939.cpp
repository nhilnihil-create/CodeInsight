#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn=110;
struct node{
	ll x;
	ll y;
	double angle;
	friend bool operator<(node a,node b){
		return a.angle<b.angle;
	}
}point[maxn];
//struct node{
//	ll x;
//	ll y;
//	double angle;
//}point[maxn];
bool cmp(node a,node b){
	return a.angle<b.angle;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>point[i].x>>point[i].y;
		point[i].angle=atan2(point[i].y,point[i].x);
	}
	sort(point,point+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ll dx=point[i].x,dy=point[i].y;
		ans=max(ans,dx*dx+dy*dy);
		for(int j=(i+1)%n;j!=i;j=(j+1)%n){
			dx+=point[j].x;dy+=point[j].y;
			ans=max(ans,dx*dx+dy*dy);
		}
	}
	double res=sqrt(ans);
//	cout<<<<endl;
	printf("%.14f\n",res);
	return 0;
}