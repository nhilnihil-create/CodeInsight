#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define inf (int)(3e18)

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
string s;
int a[1000005];
signed main() {
	cin>>N>>s;
	int sum1=0,sum2=0;
	bool flag=true;
	rep(i,N){
		a[i]=s[i]-'0';
		int now=N-1,sum=0;
		while(now)sum+=now/2,now/=2;
		now=N-i-1;
		while(now)sum-=now/2,now/=2;
		now=i;
		while(now)sum-=now/2,now/=2;
		if(!sum){
			sum1+=a[i]%2;
			sum2+=a[i]/2;
		}
		if(a[i]==2)flag=false;
	}
	if(sum1%2)cout<<1<<endl;
	else if(!flag)cout<<0<<endl;
	else if(sum2%2)cout<<2<<endl;
	else cout<<0<<endl;
}

