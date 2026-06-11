#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll cnt[100010];
int main() {
	ll n,k,q;
	cin>>n>>k>>q;
	for(ll i=0;i<q;i++){
		ll now;
		cin>>now;
		now--;
		cnt[now]++;
	}
	for(ll i=0;i<n;i++){
		ll mi=q-cnt[i];
		if(k<=mi){
			cout << "No";
		}
		else{
			cout << "Yes";
		}
		cout <<endl;
	}
	// your code goes here
	return 0;
}