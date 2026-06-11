#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string w, t;
	cin >> w;
	for(auto &c : w) c = tolower(c);

	int count = 0;
	while(cin >> t && t != "END_OF_TEXT") {
		string t0;
		for(auto &c : t) 
			if(isalpha(c))
				t0.push_back(tolower(c));
		count += (w == t0);
	}
	cout << count << endl;

	return 0;
}

