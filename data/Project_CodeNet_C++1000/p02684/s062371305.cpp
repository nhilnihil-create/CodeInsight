#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	in(a,n);
	rep(i,n)a[i]--;
	ll loop=1,town=0,visit[n];
	init(visit,n);
	while(visit[town]==0){
		visit[town]=loop;
		town=a[town];
		loop++;
	}
	loop=loop-visit[town];
	if(k<visit[town]){
		town=0;
		rep(i,k)town=a[town];
		cout<<town+1;
		return 0;
	}
	k-=visit[town]-1;
	k%=loop;
	rep(i,k)town=a[town];
	cout<<town+1;
	return 0;
}