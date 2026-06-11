#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	string tmp1, tmp2;
	int n;
	int h;
	while (cin >> s, s != "-") {
		cin >> n;
		while (n--) {
			cin >> h;
			//????????¨
			tmp1 = "";
			for (int i = 0; i < h; i++) {
				tmp1 += s[i];
			}
			//????????¨
			tmp2 = "";
			for (int i = h; i < s.size(); i++) {
				tmp2 += s[i];
			}
			s = tmp2 + tmp1;
		}
		cout << s << endl;
	}
	return 0;
}