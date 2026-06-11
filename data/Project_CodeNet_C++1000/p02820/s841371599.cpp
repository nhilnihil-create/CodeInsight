#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int n, k, r, s, p;
	string t;
	cin >> n >> k >> r >> s >> p >> t ;

	int r_c = 0, s_c = 0, p_c = 0;
	for (int i = 0;i < t.length();i++) {
		if(k > i){
			if (t[i] == 'r')r_c++;
			else if (t[i] == 's')s_c++;
			else p_c++;
		}
		else {
			if (t[i] != t[i - k]) {
				if (t[i] == 'r')r_c++;
				else if (t[i] == 's')s_c++;
				else p_c++;
			}
			else {
				t[i] = 0;
			}
		}
	}

	long long ans = 0;
	ans += r_c * p;
	ans += s_c * r;
	ans += p_c * s;
	cout << ans << endl;
	return 0;
}

