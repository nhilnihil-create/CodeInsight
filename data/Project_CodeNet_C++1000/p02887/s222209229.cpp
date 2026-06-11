#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n, i = 0, j = 1;
	cin >> n;
	string s;
	cin >> s;
	rep2(i, 1, n) {
		if (s[i] != s[i - 1]) j++;
	}
	cout <<j << endl;
	return 0;

}
