#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>
#include <list>


using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<string> str;
	string input;
	int n; cin >> n;
	while (n--) {

		cin >> input;
		str.push_back(input);

	}
	str.sort();
	str.unique();

	cout << str.size() << endl;

	return 0;
}
