#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string b;
	int i, c = 0, d = 0;
	stack<char> a;
	bool e;
	while (1) {
		getline(cin,b);
		for (i = 0; i<(int)b.size(); i++) {
				/*if (b[i] == '(') { c += 1; 
				e = true;
				}
				if (b[i] == ')') {
					c -= 1;
					e = false;
					if (c < 0||e==false) {
						c = 1;
						break; }
				}
				if (b[i] == '[') { d += 1; 
				e = false;
				}
				if (b[i] == ']') { d -= 1;
				d = true;
				if (d < 0||e==true) { 
					d = 1;
					break;
				}
				}
		*/
			if (b[i] == '(' || b[i] == '[') {
				a.push(b[i]); }
			if (a.empty())if (b[i] == ')' || b[i] == ']') { 
				a.push(b[i]);
				break; }
			if (b[i] == ')'&&a.top() == '(') { a.pop(); }
			else if (b[i] == ']'&&a.top() == '[') { a.pop(); }
			else if (b[i] == ')'&&a.top() == '[') { break; }
			else if (b[i] == ']'&&a.top() == '(') { break; }

		}

		if (b[0] == '.') { break; }
		//if (c == 0 && d == 0) 
		if(a.empty()){cout << "yes"<<endl; }
			else { cout << "no"<<endl; }
			//c = 0, d = 0;
			while (!a.empty()) { 
			a.pop();
			};
	};
	return 0;
}