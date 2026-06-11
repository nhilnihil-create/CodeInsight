#include <bits/stdc++.h>
using namespace std;

int main() {
	long a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<long> v;
	if((0 >= a && 0 <= b) || (0 >= c && 0 <= d)) {
		v.push_back(0);
	}
	v.push_back(a*c); v.push_back(a*d);
	v.push_back(b*c); v.push_back(b*d);
	cout << *max_element(v.begin(),v.end());
	return 0;
}