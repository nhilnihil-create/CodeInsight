#include <iostream>
using namespace std;
main () {
	string str;
	int n[26] = {};
	while (getline(cin, str)) {
		for (int i=0; i<str.length(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z') n[str[i]-'A']++;
			else if ('a' <= str[i] && str[i] <= 'z') n[str[i]-'a']++;
		}
	}
	for (int i=0; i<26; i++)
		cout << ((char)('a'+i)) << " : " << n[i] << endl;
}