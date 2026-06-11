#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char c;int b[1000005],a[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>c;
		b[i]=c-'0';
	}
	rep(i,1,n)a[i]=abs(b[i+1]-b[i]);
	n--;
	bool f=0;
	FOR(i,1,n){
		if(a[i]==1){
			f=1;break;
		}
	}
	int ans;
	if(!f){
		ans=2;
		FOR(i,1,n){
			if(a[i]==2)a[i]=1;
		}
	}else{
		ans=1;
		FOR(i,1,n){
			if(a[i]==2)a[i]=0;
		}	
	}
	bool anf=a[1];
	FOR(i,2,n){
		if(((i-1)&(n-1))==i-1)anf^=a[i];
	}
	if(anf){
		cout<<ans;
	}else cout<<0;
	RE 0;
}


