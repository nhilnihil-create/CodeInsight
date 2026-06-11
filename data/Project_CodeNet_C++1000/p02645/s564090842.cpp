#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
int main() {
	string s;
	cin >> s;
	string t;
	rep(i, 3) {
		t += s[i];
	}
	cout << t << endl;
	return 0;
}

