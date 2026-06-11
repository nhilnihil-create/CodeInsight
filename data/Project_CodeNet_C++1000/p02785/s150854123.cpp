#include<string>
#include<iostream>
#include <algorithm>
#include<vector>
#include<functional>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <math.h>
#include <map>
#define ll long long 
#define PI 3.14159265358979323846
#define INF 10000000000
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
using namespace std;

int main() {
	ll N, K;
    cin >> N >> K;
	vector<ll> H(N);
	rep(i, N) cin >> H[i];
	sort(H.begin(), H.end());
	ll ans = 0;
	rep(i, N - K) ans += H[i];
	cout << ans << endl;
	return 0;
}