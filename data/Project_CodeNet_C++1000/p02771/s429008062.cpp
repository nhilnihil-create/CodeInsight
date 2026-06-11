#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;


int main() {
	vector<int> data(3);
	cin >> data.at(0)>>data.at(1)>>data.at(2);
	sort(data.begin(), data.end());
	if ((data.at(0) == data.at(1) && data.at(0) != data.at(2)) || (data.at(2) == data.at(1) && data.at(0) != data.at(1))) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}