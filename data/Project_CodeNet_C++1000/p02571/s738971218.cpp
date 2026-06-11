#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iomanip>
#include <queue>

#define PI 3.14159265358979
#define MOD 1000000007

//fixed << setprecision(15) <<

using namespace std;

int main(void) {
	string s, t;
	int n,l,m,max;
	bool flag = true;
	vector <long long int> e;
	cin >> s >> t;
	max = t.size();
	n = s.size() - t.size() + 1;
	for (int i = 0; i < n; i++) {
		m = 0;
		for (int j = 0; j < t.size(); j++) {
			if (s[i + j] != t[j]) {
				m++;
			}
		}
		if (max > m)max = m;
	}
	cout << max << endl;
	/*if(flag)cout << "Yes" << endl;
		else cout << "No" << endl;*/
	return 0;
}