#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_palindrome_philia(void) {
	string s;
	cin >> s;

	int s_size_h = s.size() >> 1;

	string s_upper = s.substr(0, s_size_h);

	int h_start = s.size() % 2 == 1 ? s_size_h + 1 : s_size_h;

	string s_lower = s.substr(h_start, s_size_h);
	int hug_cnt = 0;
	for (int i = 0; i < s_size_h; i++) {
		if (s_upper[i] != s_lower[s_size_h - i-1]) hug_cnt++;
	}

	cout << hug_cnt << endl;
}

int main()
{
    b_palindrome_philia();

    return 0;
}