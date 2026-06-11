#include <algorithm>
#include <iostream>
#include <vector>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

int N;
int main() {
	cin >> N;
	vector<int> A(N);
	rep(i, 0, N) cin >> A[i];

	sort(ALLR(A));

	ll ans = A[0];
	int t = N-2, i = 1;
	while(1){
		if(t <= 0) break;
		ans += A[i]; t--;
		if(t <= 0) break;
		ans += A[i]; t--;
		i++;
	}

	cout << ans << endl;
	return 0;
}
