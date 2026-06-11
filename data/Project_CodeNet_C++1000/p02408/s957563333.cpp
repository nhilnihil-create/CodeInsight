#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const double PI = acos(-1.0);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> v;
	
	v.push_back(0);
	for(int i = 1; i <= 52; i++) {
		v.push_back(i);
	}
	
	for(int i = 0; i < n; i++) {
		int num;
		string str;
		cin >> str >> num;
		
		int x = 0;
		if(str == "S") x = 0;
		if(str == "H") x = 1;
		if(str == "C") x = 2;
		if(str == "D") x = 3;
		
		num = num + x * 13;
		v[num] = v[num] - num;
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 1; i <= 52; i++) {
		if(v[i] != 0) {
			int r = v[i] % 13;
			int d = (v[i] - 1) / 13;
			if(d == 0) cout << "S";
			if(d == 1) cout << "H";
			if(d == 2) cout << "C";
			if(d == 3) cout << "D";
			if(r == 0) r = 13;
			cout << " " << r << "\n";
		}
	}
	
	return 0;
}