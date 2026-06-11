#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	bool ac[100010]={false};
	ll wa[100010]={};
	for(ll i=0;i<m;i++){
		ll now;string s;
		cin>>now>>s;
		now--;
		if(s=="WA"){
			if(ac[now]==false){
				wa[now]++;
			}
		}
		else{
			ac[now]=true;
		}
	}
	ll accnt=0;ll wacnt=0;
	for(ll i=0;i<n;i++){
		if(ac[i]){
			accnt++;
			wacnt+=wa[i];
		}
	}
	cout << accnt<<" "<<wacnt;
	// your code goes here
	return 0;
}