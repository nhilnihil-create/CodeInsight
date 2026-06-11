	#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 

typedef long long ll;
using namespace std;
const ll m = 1e9 + 7;

int main() {
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res += s[i] - '0';
		
	}	
	if (res % 9 == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

    return 0;
}