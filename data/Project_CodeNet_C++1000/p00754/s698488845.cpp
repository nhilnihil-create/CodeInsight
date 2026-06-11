#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
using namespace std;
int main() {
	string a;
	while (getline(cin,a)&&a != ".") {
		vector<char>b;
		bool l = true;
		vector<char>::iterator it = b.begin(), it2;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(' || a[i] == '[') {
				b.push_back(a[i]);
			}
			else if (a[i] == ')' || a[i] == ']') {
				if (b.size() != 0) {
					it = b.end();
					it--;
					if (!((a[i] == ')' && (*it) == '(') || (a[i] == ']' && (*it) == '['))) {
						l = false;
					}
					b.erase(it);
				}
				else
					l = false;
			}
		}
		if (l&&b.size()==0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}