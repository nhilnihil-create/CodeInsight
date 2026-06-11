#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[200010],b[200010];
priority_queue<pair<ll,ll>> que;
int main() {
	ll n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		b[i]=x;
		if(a[i]!=b[i]){
		que.push(make_pair(x,i));
		cnt++;
		}
	}
	ll ans=0;
	while(cnt!=0){
		pair<ll,ll> kari=que.top();
		que.pop();
		ll nowval=kari.first;
		ll nowiti=kari.second;
		ll l=nowiti-1,r=nowiti+1;
		if(l<0){
			l=n-1;
		}
		if(r==n){
			r=0;
		}
		ll lval=b[l],rval=b[r];
		ans++;
		nowval-=(lval+rval);
		ll herasu=(nowval-a[nowiti])/(lval+rval);
		ans+=herasu;
		  nowval-=herasu*(lval+rval);
		b[nowiti]=nowval;
		if(nowval<a[nowiti]){
			cout << "-1";
			return 0;
		}
		if(nowval==a[nowiti]){
			cnt--;
		}
		else{
		que.push(make_pair(nowval,nowiti));
		}
	}
	cout << ans;
	// your code goes here
	return 0;
}