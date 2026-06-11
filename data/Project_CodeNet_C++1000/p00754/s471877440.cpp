#include<iostream>

using namespace std;

int main(void) {
	string in;
	char tmp;
	int pos, count, dir, tmppos;

	while(true) {
		getline(cin, in);
		if(in == ".") { break; }
		pos = 0;
		count = 0;
		dir = 1;
		while(true) {
			if(dir == 1 && (in[pos] == '(' || in[pos] == '[')) {
				count++;
			} else if(dir == 1 && (in[pos] == ')' || in[pos] == ']')) {
				tmp = in[pos];
				tmppos = pos;
				dir = -1;
			} else if(dir == -1 && ((in[pos] == '(' && tmp == ')') || (in[pos] == '[' && tmp == ']'))) {
				count--;
				in[pos] = '*';
				in[tmppos] = '*';
				dir = 1;
			} else if(dir == -1 && ((in[pos] == '(' && tmp == ']') || (in[pos] == '[' && tmp == ')'))) {
				break;
			}
			pos += 1*dir;
			if(pos < 0) { count++; break; }
			if((int)in.length() < pos) { break; }
		}
		if(count == 0) { cout << "yes" << endl; }
		else { cout << "no" << endl; }
	}

	return 0;
}