#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 2e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,fa[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,0,20){
		if((1<<i)==n){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes\n";
	if(n==3){
		rep(i,2,6)cout<<i-1<<" "<<i<<endl;
		return 0;
	}
	int k=1;
	while(k<n)k<<=1;
	k>>=1;
	rep(i,2,k-1)fa[i]=i-1;
	fa[n+1]=k-1;
	rep(i,n+2,n+k-1)fa[i]=i-1;
	for(int i=k;i<n;i+=2){
		fa[i]=2;fa[i+1]=i;
		fa[n+i]=n+i+1;fa[n+i+1]=k-1;
	}
	if(n%2==0){
		int tmp = (n-k)^2;
		if(tmp==0){
			fa[n]=k;fa[n+n]=2;
		}else{
			fa[tmp]=2;
			fa[tmp+1]=tmp-1;
			fa[3]=tmp;
			
			fa[n+tmp]=n+2;
			fa[n+tmp+1]=n+tmp-1;
			fa[n+3]=n+tmp;
			
			fa[n]=k;fa[n+n]=tmp;
		}
	}
	rep(i,2,n*2)cout<<fa[i]<<" "<<i<<endl;
	return 0;
}