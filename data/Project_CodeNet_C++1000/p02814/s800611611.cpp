#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

ll gcd(ll a, ll b) { 
	if (b==0)
		return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b) { 
	return a/gcd(a,b)*b;
}

 
int main () {
	int N, M;
    cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	rep(i,N) {
		cin >> A[i];
		B[i] = A[i]/2;
	}
	ll l = 1;
	for (int i = 0; i < N; i++) {
		l = lcm(l,B[i]);
	}
	for (int i = 0; i < N; i++) {
		if ((l/B[i])%2==0) {
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = M / l;
	ans = (ans + 1)/2;
	cout << ans << endl;
    return 0;
}