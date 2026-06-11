#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<utility>
#include<iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int ans = log(n) / log(k) + 1;
	cout << ans;

}

