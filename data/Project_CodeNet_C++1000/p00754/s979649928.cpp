#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)) {
		if(s == ".") break;
		vector<int> v(2);
		vector<int> tmp[2];
		bool f = true;
		for(auto& c: s) {
			if(c == '(') {
				v[0]++;
				tmp[0].push_back(v[1]);
			}
			if(c == ')') {
				if(v[0] == 0 || tmp[0].back() != v[1]) {
					f = false;
					break;
				}
				else {
					v[0]--;
					tmp[0].pop_back();
				}
			}
			if(c == '[') {
				v[1]++;
				tmp[1].push_back(v[0]);
			}
			if(c == ']') {
				if(v[1] == 0 || tmp[1].back() != v[0]) {
					f = false;
					break;
				}
				else {
					v[1]--;
					tmp[1].pop_back();
				}
			}
		}
		if(v[0] != 0 || v[1] != 0) f = false;
		cout << (f ? "yes" : "no") << endl;
	}
}