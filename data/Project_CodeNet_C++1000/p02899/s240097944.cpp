#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[100010];
	ll ans[100010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
		ch[i]--;
		ans[ch[i]]=i;
	}
	for(ll i=0;i<n;i++){
		cout <<ans[i]+1<<" ";
	}
	// your code goes here
	return 0;
}