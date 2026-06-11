#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
   
int sum(int l, int r) {

	return (l + r)*(r - l + 1) / 2;

}

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}

}

int32_t  main() {

	IOS;

	int N;
	cin >> N;

	string S;
	cin >> S;
	int cnt = 0;

	int r = 0;
	int g = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {

		if (S[i] == 'R') {
			r++;
		}
		else if (S[i] == 'G') {
			g++;
		}
		else {
			b++;
		}

	}

	int tot = r * g*b;

	int rgb = (int)('R') + (int)('G') + (int)('B');

	for (int i = 0; i < N; i++) {

		for (int j = i + 1; j < N; j++) {

			int k = 2 * j - i;

			if (k < N) {

				if ((int)S[i] + (int)S[j] + (int)S[k] == rgb) {

					tot--;

				}

			}

		}


	}

	
	


	cout << tot << endl;

}
