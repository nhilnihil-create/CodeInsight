#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<ll>A,B,C;
	for(ll i=0;i<a;i++){
		ll now;
		cin>>now;
		A.push_back(now);
	}
	for(ll i=0;i<b;i++){
		ll now;
		cin>>now;
		B.push_back(now);
	}
	for(ll i=0;i<c;i++){
		ll now;
		cin>>now;
		C.push_back(now);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	priority_queue<ll>qa,qb;
	for(ll i=0;i<x;i++){
		qa.push(-1*A[a-i-1]);
	}
	for(ll i=0;i<y;i++){
		qb.push(-1*B[b-i-1]);
	}
	for(ll i=0;i<c;i++){
		ll now=-1*C[i];
		ll nowa=qa.top();
		ll nowb=qb.top();
		if(nowa<nowb){
			if(now<nowb){
				qb.pop();
				qb.push(now);
			}
		}
		else{
			if(now<nowa){
				qa.pop();
				qa.push(now);
			}
		}			
	}

	ll ans=0;
	while(qa.size()!=0){
		ll now=qa.top();
		qa.pop();
		ans+=now;
//		cout <<now<<endl;
	}
//	cout <<endl;
	while(qb.size()!=0){
		ll now=qb.top();
		qb.pop();
		ans+=now;
//		cout <<now<<endl;
	}
//	cout <<endl;
	cout <<abs(ans);
	// your code goes here
	return 0;
}