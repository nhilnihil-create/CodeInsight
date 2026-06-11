#include <bits/stdc++.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define int long long
#define mod 1000000007
#define INF LLONG_MAX/5
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
int x[300000];
signed main(){
	int n;
	cin>>n;
	f(i,n){
		int a;
		cin>>a;
		x[a-1]++;
	}
	sort(x,x+n);
	for(int i=1;i<=n;i++){
		int z=0,cnt=0;
		while(i*cnt<=z){
			z+=n-(lower_bound(x,x+n,cnt+1)-x);
			cnt++;
		}
		cout<<cnt-1<<endl;
	}
}
