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
	int n,m,x;
	cin>>n>>m>>x;
	int c[n],a[n][m];
	rep(i,n){
		cin>>c[i];
		rep(j,m){
			cin>>a[i][j];
		}
	}
	int minPrise=10000000,sum[m],prise,flag;
	for(int i=0;i<pow(2,n);i++){
		init(sum,m);
		prise=0;
		rep(j,n){
			if(i>>j&1){
				prise+=c[j];
				rep(l,m)sum[l]+=a[j][l];
			}
		}
		flag=1;
		rep(j,m)if(sum[j]<x)flag=0;
		if(flag!=0)minPrise=min(prise,minPrise);
	}
	if(minPrise==10000000)cout<<-1;
	else cout<<minPrise;
	return 0;
}