#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	
	vector< string > days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	string s;
	cin >> s;
	int pos = -1;
	while (++pos < (int) days.size()) {
		if (days[pos] == s) break;
	}
	
	int i;
	for (i=pos+1; i<(int)days.size(); i++) {
		if (days[i] == "SUN") break;
	}
	cout << i - pos << '\n';
	
	
	
	return 0;
}
