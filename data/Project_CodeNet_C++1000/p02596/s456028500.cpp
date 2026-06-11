#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int main() {
	int k, ans;
	int num;
	while(cin >> k) {
		ans = 1;
		num = 7;

		while(num%k != 0 && ans < 1000000) {
			num %= k;
			num = num*10+7;
			ans++;
		}
		if(ans != 1000000)
			cout << ans << endl;
		else
			cout << "-1" << endl;
	}
}