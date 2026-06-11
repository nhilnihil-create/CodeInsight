#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>
#include <list>

#define ll long long int
using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int rgb[3][4005];
	int rgb_c[3] = {};
	bool flag[3] = {};


	int n;
	cin >> n;
	string str;
	cin >> str;
	ll count = 0;
	for (int i = n - 1; i >= 0; i--) {
		switch (str[i]) {
		case 'R':
			rgb_c[0] += 1;
			break;
		case 'G':
			rgb_c[1] += 1;
			break;
		case 'B':
			rgb_c[2] += 1;
			break;
		}
		rgb[0][i] = rgb_c[0];
		rgb[1][i] = rgb_c[1];
		rgb[2][i] = rgb_c[2];
	}
	


	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			switch (str[i]) {
			case 'R':
				flag[0] = true;
				break;
			case 'G':
				flag[1] = true;
				break;
			case 'B':
				flag[2] = true;
				break;
			}
			switch (str[j]) {
			case 'R':
				flag[0] = true;
				break;
			case 'G':
				flag[1] = true;
				break;
			case 'B':
				flag[2] = true;
				break;
			}

			if (flag[0] && flag[1]) {
				count += rgb[2][j + 1];
				if (2*j-i<n &&str[2 * j + -i] == 'B')count--;
			}
			if (flag[1] && flag[2]) {
				count += rgb[0][j + 1];
				if (2 * j - i < n && str[2 * j + -i] == 'R')count--;
			}
			if (flag[2] && flag[0]) {
				count += rgb[1][j + 1];
				if (2 * j - i < n && str[2 * j + -i] == 'G')count--;
			}
			flag[0] = false;
			flag[1] = false;
			flag[2] = false;
		}
	}

	cout << count << endl;








	return 0;
}
