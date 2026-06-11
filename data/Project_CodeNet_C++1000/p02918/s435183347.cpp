#include <iostream>
#include <string>
#include <algorithm>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::min;

int main() {
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	
	string::size_type count = 0;
	
	for (int i = 0; i != s.size() - 1; ++i) {
		
		if (s[i] == s[i + 1])
			++count;
	}
	
	count += k * 2;
	count = min(count, s.size() - 1);
	
	cout << count << endl;
	
	return 0;
}