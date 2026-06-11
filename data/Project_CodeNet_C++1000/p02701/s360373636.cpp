#include <iostream>
#include <set>
using namespace std;

int main() {
	set<string> hash;
	string str;
	int case_num = 0;
	cin >> case_num;
	for (int i = 0; i < case_num; ++i) {
		cin >> str;
		hash.insert(str);
	}
	cout << hash.size();
	return 0;
}
