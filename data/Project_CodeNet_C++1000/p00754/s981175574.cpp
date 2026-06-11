#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	map<char, int> conv;
	conv['('] = 0;
	conv[')'] = 0;
	conv['['] = 1;
	conv[']'] = 1;

	map<char, int> mode;
	mode['('] = 1;
	mode[')'] = -1;
	mode['['] = 1;
	mode[']'] = -1;

	string str;
	while ( getline(cin, str), str != "." ) {
		vector<int> prev;
		int nest = 0;
		bool ans = true;
		for (int i = 0; i < str.size(); ++i) {
			if (conv.find(str[i]) != conv.end()) {
				int bid = conv[str[i]];
				if (mode[str[i]] < 0) {
					if (nest <= 0 || prev[nest-1] != bid) ans = false;
					--nest;
				}
				else {
					if (++nest > prev.size()) prev.push_back(bid);
					else prev[nest-1] = bid;
				}
				if (!ans) break;
			}
		}
		if (nest != 0) ans = false;
		if (ans) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}