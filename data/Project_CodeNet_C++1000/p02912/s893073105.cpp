#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main(){
	ll n,m;
	cin >> n >> m;
	priority_queue<ll> que;
	for(ll i=0;i<n;i++){
		ll a;
		cin >> a;
		que.push(a);
	}
	if(n==1){
		ll b=que.top();
		for(ll i=0;i<m;i++){
			b/=2;
		}
		cout << b << endl;
		return 0;
	}
	while(m>=1){
		ll b=que.top();
		que.pop();
		b/=2;
		que.push(b);
		m--;
	}
	ll res=0;
	while(!que.empty()){
		ll c=que.top();
		que.pop();
		res+=c;
	}
	cout << res << endl;
	return 0;
}
