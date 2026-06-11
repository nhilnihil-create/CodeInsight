#pragma GCC optimize("Ofast,unroll-loops")
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
int cnt[300005],q[300005],n;
bool check(int p,int x){
	int t=upper_bound(cnt+1,cnt+n+1,x)-cnt-1;
	RE (q[t]+(n-t)*x>=p*x);
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;cnt[x]++;
	}
	sort(cnt+1,cnt+n+1);
	FOR(i,1,n)q[i]=q[i-1]+cnt[i];
	int ans=n-1;
	cout<<n<<'\n';
	FOR(i,2,n){
		while(!check(i,ans))ans--;
		cout<<ans<<'\n';
	}
	RE 0;
}



