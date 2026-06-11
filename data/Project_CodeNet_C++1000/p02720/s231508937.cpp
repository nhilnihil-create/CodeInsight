#include <bits/stdc++.h>
using namespace std;
int K;
string x;
int ge(string n) {
	return n[n.size() - 1] - '0';
}
int shi(string n) {
	return n[n.size() - 2] - '0';
}
void make(string &x) {
	if(ge(x) >= min(shi(x) + 1, 9)) {
		//进位
		int pos = x.size() - 2;
		while(pos > 0 && x[pos] >= min(char(x[pos - 1] + 1), '9')) {
			pos--;
		}
		if(pos == 0 && x[0] == '9') {
			int len = x.size();
			x = "1";
			for(int i = 1; i <= len; i++)x += "0";
			//cout << x << endl;
			return ;
		}
//		pos++;
		x[pos]++;
		for(int j = pos + 1; j < x.size(); j++) {
			if(x[j - 1] == '0')x[j] = '0';
			else x[j] = x[j - 1] - 1;
		}
	}
	else {
//		printf("****");
//		cout <<ge(x) << ' ' << shi(x) << endl;
		x = x.substr(0, x.size() - 1) + char(ge(x) + '1');
	}
//	cout << x << endl; 
}
int main() {
	cin >> K;
	if(K <= 10) {
		cout << K << endl;
		return 0;
	}
	K -= 10;
	x = "10";
	while(K--) {
		make(x);
	}
	cout << x << endl;
	return 0;
}