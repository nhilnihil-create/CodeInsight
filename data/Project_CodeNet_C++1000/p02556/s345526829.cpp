#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 999999999999999;
struct str{
	int x,y;
}st[N];
int a[N],b[N];

signed main(){
	int n;
	cin>>n;
	int mx=0,nx=inf;
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>st[i].x>>st[i].y;
		a[i]=st[i].x+st[i].y;
		b[i]=st[i].x-st[i].y;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	cout<<max(-1*a[1]+a[n],-1*b[1]+b[n]);
	return 0;
}