#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
 
using namespace std;
using ll = long long;
 
 
int main() {
 
	ll N;
	cin >> N;
	
	vector<ll> d(N);
	
	rep(i, N){
		cin >> d[i];
	}
	
	sort(d.begin(), d.end());
	
	ll M, ans;
	M =(N + 1)/2;
	
	ans = d[M] - d[M-1];
	
	cout << ans;
	
	return 0;
}