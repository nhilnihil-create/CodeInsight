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

	double d, t, s;
	cin >> d >> t >> s;
	if ((d / s) <= t) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}