#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	int n;
	while (cin >> n&&n != 0) {
		map<char, char>a;
		string s = "";
		for (int i = 0; i < n; i++) {
			char b, c;
			cin >> b >> c;
			a.insert(map<char, char>::value_type(b, c));
		}
		cin >> n;
		map<char, char>::iterator it;
		for (int i = 0; i < n; i++) {
			char b;
			cin >> b;
			it = a.find(b);
			if (it == a.end())
				s += b;
			else
				s += a[b];
		}
		cout << s << endl;
	}
}