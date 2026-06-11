#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_strings_with_the_same_length(void) {
	int n;
	string s, t;
	cin >> n >> s >> t;
	
	for (int i = 0; i < n; i++) {
		cout << s[i] << t[i];
	}

	cout << endl;
}

int main()
{
    b_strings_with_the_same_length();

    return 0;
}