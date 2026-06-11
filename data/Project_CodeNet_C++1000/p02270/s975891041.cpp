#include <bits/stdc++.h>
#define inf (1<<29)
#define sq(n) ((n)*(n))
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define MEMSET(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
using ll = long long;

ll n,k,w[100000];

int f(ll p){
	int i=0;
	rep(j,k){
		int s=0;
		while(s+w[i]<=p){
			s+=w[i++];
			if(i==n)return n;
		}
	}
	return i;
}

signed main(){
	cin>>n>>k;
	rep(i,n)cin>>w[i];
	ll l=0,r=1000000000;
	while(r-l>1){
		ll m=(l+r)/2;
		if(f(m)>=n)r=m;
		else l=m;
	}
	cout<<r<<endl;
	return 0;
}
