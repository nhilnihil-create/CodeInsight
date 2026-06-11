#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define P pair<int,int>
#define SIZE 200010 

ll n,m,v,p,A[SIZE];

bool check(int d){
	if(d>=n-p) return true;
	ll lim=A[d]+m,zan=m*(v-p),cnt=0;
	for(int i=0;i+p<=n;i++){
		if(i==d) continue;
		ll c=min(m,lim-A[i]);
		if(c<0) return false;
		zan-=c;
	}
	return zan<=0;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin>>n>>m>>v>>p;
	for(int i=0;i<n;i++) cin>>A[i];
	sort(A,A+n);
	ll l=-1,r=n;
	while(r-l>1){
		int d=(l+r)/2;
		if(check(d)) r=d;
		else l=d;
	}
	cout<<n-r;
	return 0;
}