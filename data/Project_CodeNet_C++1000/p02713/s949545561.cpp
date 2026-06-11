#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
int main() {
	int k; cin >> k;
	int g = 0;
	long long ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++) {
				for (int n = 1; n <= min(i, min(j, l)); n++) {
					if (i % n == 0 && j % n == 0 && l % n == 0) {
						g=n;
					}
				}
				ans += g;
				g = 0;
			}
		}
	}
	cout<<ans<<endl;
}