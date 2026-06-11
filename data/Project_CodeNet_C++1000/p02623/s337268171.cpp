#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
	
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	ll a,b,sa[n+1],sb[m+1];
	sa[0]=0;
	sb[0]=0;
	rep(i,n){
		cin>>a;
		sa[i+1]=sa[i]+a;
	}
	rep(i,m){
		cin>>b;
		sb[i+1]=sb[i]+b;
	}
	int pb=0;
    ll sum=0;
	ll rest=0;
	rep(i,n+1){
		rest=k-sa[i];
		pb=upper_bound(sb,sb+m+1,rest)-sb-1;
		if(pb<0)continue;
		if(sum<i+pb)sum=i+pb;
	}
	cout<<sum;
	return 0;
}
