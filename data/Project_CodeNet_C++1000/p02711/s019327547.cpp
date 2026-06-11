
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s[i] == '7') {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	
}