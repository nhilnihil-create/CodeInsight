#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> v(n);
	for(int &e : v)
		cin >> e;
	
	vector<int> v2 = v;
	sort(v2.rbegin(), v2.rend());
	
	for(int &e : v)
		cout << (e == v2[0] ? v2[1] : v2[0]) << '\n';
}
