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
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<ll> a(200001);


int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	if (n == 1){
		cout << 0 << endl;
		return 0;
	}
	sort(a.begin(), a.begin() + n, greater<ll>());
	ll ans = a[0];
	if (n == 2){
		cout << ans << endl;
		return 0;
	}
	int coun = 1;
	for (int i = 1; ; i++){
		ans += a[i];
		coun++;
		if (coun == n-1) break;
		ans += a[i];
		coun++;
		if (coun == n-1) break;
	}
	cout << ans << endl;
	return 0;
}