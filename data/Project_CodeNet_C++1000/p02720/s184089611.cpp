#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

set<ll>q;
void dep(ll now,ll cnt){
	if(cnt==12){
		return ;
	}
	q.insert(now);
	dep(now*10+now%10,cnt+1);
	if(now%10!=0){
		dep(now*10+now%10-1,cnt+1);
	}
	if(now%10!=9){
		dep(now*10+now%10+1,cnt+1);
	}
}
int main() {
	ll n;
	cin>>n;
	for(ll i=1;i<=9;i++){
		dep(i,0);
	}
	auto itr=q.begin();
	for(ll i=0;i<n-1;i++){
		itr++;
	}
	cout << *itr;
	return 0;
}