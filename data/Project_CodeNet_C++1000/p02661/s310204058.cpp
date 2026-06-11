#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(v) v.begin(), v.end()
#define MOD 1e7
const long long INF = 1LL<<60;

int main() {
	// your code goes here
	int n;cin>>n;
	vector<ll> x1(n), x2(n);
	rep(i, n)   cin>>x1[i]>>x2[i];
	sort(all(x1));
	sort(all(x2));
	if(n%2==0) {
	    ll ma = x1[n/2-1]+x1[n/2];
	    ll mb = x2[n/2-1]+x2[n/2];
	    cout<<mb-ma+1<<endl;
	} else {
	    ll ma = x1[n/2], mb = x2[n/2];
	    cout<<mb-ma+1<<endl;
	}
	return 0;
}