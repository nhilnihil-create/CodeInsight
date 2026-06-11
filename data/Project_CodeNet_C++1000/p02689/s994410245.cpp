#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
int main(){
	int n,m;
	cin>>n>>m;
	int h[n+1];
	rep(i,n)cin>>h[i+1];
	int a,b;
	int good[n+1];
	rep(i,n+1)good[i]=1;
	rep(i,m){
		cin>>a>>b;
		if(h[a]>=h[b]){
			good[b]=0;
		}
		if(h[a]<=h[b]){
			good[a]=0;
		}
	}
	int count=0;
	rep(i,n)count+=good[i+1];
	cout<<count;
	return 0;
}