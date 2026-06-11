#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, p = 0, cnt;
	string key[] = {"", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string str;
	
	cin >> n;
	while (cin >> str) {
		for (char& c : str) {
			n = c - '0';
			if (n) {
				cnt++;
			} else if (p == n) {
			}else {
				cout << key[p][(cnt-1) % key[p].size()];
				cnt = 0;
			}
			p = n;
		}
		cout << endl;
	}
	
	return 0;
}