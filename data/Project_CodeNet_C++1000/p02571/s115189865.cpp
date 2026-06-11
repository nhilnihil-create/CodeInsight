#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include<cmath>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <stack>
#include <climits>
#define PI 3.14159265
#define ll long long
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
const int N = 1e6;
using namespace std;
void RUN() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
}
//vector<int>v1(10000), v2(100005), v3(100005);

int main() {
	RUN();

	string s, t;
	cin >> s >> t;
	int mn = INT_MAX;
	for (int i = 0; i < sz(s); i++) {
		for (int j = 0; j < sz(s); j++) {
			if (j - i + 1 == sz(t)) {
				int indx = 0, c = 0;
				for (int k = i; k <= j; k++) {
					if (s[k] != t[indx]) {
						c++;
					}
					indx++;
				}
				if (c < mn) {
					mn = c;
				}
			}
		}
	}
	cout << mn;
}