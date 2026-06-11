#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{   
    int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	ll ans = a[0];
	ll index = 1;
	n--;
	n--;
	bool next = false;
	while (n--) {
		ans += a[index];
		if (next) {
			index++;
			next = false;
		}
		else {
			next = true;
		}
	}
	cout << ans << endl;
    return 0;
}