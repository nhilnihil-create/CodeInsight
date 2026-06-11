#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;

int main()
{
	int n, m;
	cin >> n >> m;
	int wa = 0;
	int ac = 0;
	vector<pair<int, string>> ss(m);
	vector<bool> aow(n);
	vector<int> wwa(n);
	rep(i, n) {
		aow[i] = false;
	}
	rep(i, m) {
		int ff;
		cin >> ff;
		string sa;
		cin >> sa;
		if (aow[ff - 1] == false) {
			if (sa == "WA")
				wwa[ff - 1]++;
			if (sa == "AC") {
				aow[ff - 1] = true;
			}
		}
	}
	rep(i, n) {
		if (aow[i]) {
			wa += wwa[i];
			ac++;
		}
	}
	cout << ac << " " << wa;
}

