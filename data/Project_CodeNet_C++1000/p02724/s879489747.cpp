#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;

int main(){
	int x;	cin >> x;
	int ans = 0;

	ans += x / 500 * 1000;
	x -= x / 500 * 500;
	ans += x / 5 * 5;

	cout << ans << endl;

	return 0;
}
