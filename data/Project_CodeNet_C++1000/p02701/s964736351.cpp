

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = 1e9 + 7;


int main(int argc, char* argv[]) {
	
	int n;
	cin >> n;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string si;
		cin >> si;
		s.insert(si);
	}

	cout << s.size() << endl;
}