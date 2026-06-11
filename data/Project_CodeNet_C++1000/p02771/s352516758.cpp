#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	set<int> s;
	int a, b, c;
	cin >> a >> b >> c;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	if (s.size() == 2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
