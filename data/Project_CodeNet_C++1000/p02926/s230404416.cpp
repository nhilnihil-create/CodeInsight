#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll maxn = 1e6+10;
const ll inf = 1e14;
struct node{
	ll x,y;
	 
}r[1100];
bool cmp(node a,node b){
	return atan2(a.y,a.x) < atan2(b.y,b.x);
	
}
int main(){
	ll n,x,y;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> r[i].x >> r[i].y;
	}
	ll ans = 0;
	sort(r,r+n,cmp);
	for(ll i = 0; i < n; i++){
		x = r[i].x ; y = r[i].y;
		ans = max(ans,x*x+y*y);
		for(ll j = (i+1)%n; j != i; j = (j+1)%n){
			x += r[j].x ; y += r[j].y;
			ans = max(ans,x*x+y*y);
		}

	}

	double ans1 = sqrt(ans);
	printf("%.13lf\n",ans1);
//	for(int i=0;i<n;i++)
//	{
//		printf("%d %d\n",r[i].x,r[i].y);
//	}
	return 0;
}