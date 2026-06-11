#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int g = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'G') {
			g++;
		}
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] != s[j] && s[i] != 'G' && s[j] != 'G') {
				r += g;
				if (2*j-i < n && s[j + j - i] == 'G') {
					r--;
				}
				if (2*i - j >= 0 && s[2*i-j] == 'G') {
					r--;
				}
				if (((i+j+1)&1) && s[(i+j)/2] == 'G') {
					r--;
				}
			}
		}
	}
	cout << r;
}
	