#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

#define INF 1e9

ll n, k;
int main() {
	cin >> n >> k;
	vector<int> a(n);
	rep(i, 0 ,n){
		 int tmp; cin  >> tmp;
		 a[i] = tmp-1;
	}
	
	vector<bool> seen(n,false);
	int root = 0;
	while(1){
		if(seen[root]) break;
		seen[root] = true;
		root = a[root];
		k--;
		if(k <= 0) {
			cout << root+1 << endl;
			return 0;
		}
	}
		
	int roopCount = 1, now = a[root];
	while(1){
		if(root == now)break;
		now = a[now];
		roopCount++;
	}
	
	k += roopCount;
	k %= roopCount;
	
	int ans = root;
	rep(i, 0, k){
		ans = a[ans];
	}
	
	cout << ans + 1 << endl;
    return 0;
}
