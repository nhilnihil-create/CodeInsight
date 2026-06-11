#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	long long a;
	double b;
	cin >> a >> b;
	b = b * 100 + 0.5;
	long long b_dash = b;
	cout << (a * b_dash) / 100 << endl;
	return 0;
}