#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int outlet = 1;
	int count = 0;
	while (outlet < B) {
		outlet = outlet - 1 + A;
		count++;
	}
	cout << count << endl;
	return 0;
}