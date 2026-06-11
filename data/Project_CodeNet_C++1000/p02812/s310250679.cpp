#include<iostream>
using namespace std;
#include <vector>
#define re(i,n) for(int i = 0; i < n; i++)

int main() {
	int n;
	string s;
	bool b = false;
	int cnt = 0;
	cin >> n >> s;
	re(i, n-2) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')cnt++;
	}
	cout << cnt << endl;
	return 0;
}