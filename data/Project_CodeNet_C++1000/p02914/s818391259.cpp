#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;int x=0;
	FOR(i,1,n){
		cin>>a[i];x=x^a[i];
	}
	int t=((1ll<<60)-1)^x,l,ans=0,c;
	FOR(i,1,n)a[i]=a[i]&t;
	for(int i=59;i>=0;i--){
		t=(1ll<<i);l=-1;
		FOR(j,1,n){
			if(t&a[j]){
				l=j;break;
			}
		}
		if(l==-1)continue;
		if(!(ans&t))ans=ans^a[l];
		c=a[l];
		FOR(j,l,n){
			if(t&a[j])a[j]=a[j]^c;
		}
	}
	cout<<ans*2+x;
	RE 0;
}

