#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (ll)(n); ++i)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		double ss=i*1.08;
		int a=floor(ss);
		if(a==n) {
			cout << i << endl;
			return 0;
		} 
	}
	cout << ":(" << endl;
}