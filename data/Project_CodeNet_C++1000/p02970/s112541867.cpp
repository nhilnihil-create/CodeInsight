#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;



int main() {
	int n, d,sum=0,ans=0;
	cin >> n >> d;
	while (sum < n) {
		sum += 2*d+1;
		ans++;
	}
	cout << ans << endl;

	return 0;
}