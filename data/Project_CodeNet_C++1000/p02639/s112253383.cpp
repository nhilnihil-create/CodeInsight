#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int x[5], ans;

	rep(i,5) cin >> x[i];

	rep(i, 5){
		ans = i+1;
		if (x[i] == 0)break;
	}

	cout << ans << endl;

	return 0;
}