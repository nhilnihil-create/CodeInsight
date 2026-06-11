#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 200100;
ll n, k;
ll arr[maxn];

bool valid(ll x) {
	ll cnt = 0LL;
	for(int i=1;i<=n;i++) {
		cnt += ((arr[i] + x - 1) / x - 1);
	}
	return cnt <= k;
}

int main() {
	cin>>n>>k;
	ll maxval = 0LL;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		maxval = max(maxval, arr[i]);
	}

	ll result = maxval;
	for(ll cekor=maxval;cekor>0;cekor/=2) {
		while(result - cekor >= 1 && valid(result-cekor)) result -= cekor;
	}
	cout<<result<<"\n";
}