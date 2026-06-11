#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define INF 1000000001
#define INFL 1000000000000000001
#define M 1000000007
string s;
ll n,k;
vector<ll>q;
int main(void){
	cin>>s>>k;
	n=s.size();
	ll l=1;
	for(int i=1;i<=n;i++){
		if(i==n||s[i-1]!=s[i]){
			q.PB(l);
			l=0;
		}
		l++;
	}
	ll ans=0;
	if(s[0]!=s[n-1]){
		for(int i=0;i<q.size();i++)ans+=q[i]/2LL;
		ans*=k;
	}else{
		if(q.size()==1){
			ans=n*k/2LL;
		}else{
			for(int i=1;i+1<q.size();i++)ans+=q[i]/2LL;
			ans+=(q[0]+q.back())/2LL;
			ans*=(k-1LL);
			for(int i=0;i<q.size();i++)ans+=q[i]/2LL;
		}
	}
	printf("%lld\n",ans);
}
