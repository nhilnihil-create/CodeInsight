#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const int MODD = 998244353;
const ll LLINF = 1e18;

ll dub[62][200001];

int main(){
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; i++){
		dub[0][i] = a[i];
	}
	
	for (int i = 1; i <= 60; i++){
		for (int j = 0; j < n; j++){
			dub[i][j] = dub[i-1][dub[i-1][j]];
		}
	}

	ll ans = 0;
	for (int i = 0; i <= 60; i++){
		if (k & (1LL<<i)){
			ans = dub[i][ans];
		}
	}
	cout << ans+1 << endl;
	return 0;
}
