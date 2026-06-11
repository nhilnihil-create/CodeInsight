#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	string s;
	cin >> s;

	int index = s.length() / 2 - 1;
	bool flags = true;
	int N = s.length();
	for (int i = 0; i < (N - 1) / 2; ++i) {
		if(s[i] == s[i + (N + 3) / 2 - 1]){
			//pass;
		}
		else {
			flags = false;
			break;
		}
	}

	if (flags)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}