#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	string str, order, buf;
	int q, a, b;
	
	cin >> str >> q;

	for (int i =0;i<q;i++){
		cin >> order >> a >> b;
		if (order == "print") {
			cout << str.substr(a, b - a + 1) << "\n";
		}
		else if (order == "reverse") {
			buf = str.substr(a, b - a + 1);
			reverse(buf.begin(), buf.end());
			str = str.replace(a, b - a + 1, buf);
		}
		else if (order == "replace") {
			cin >> buf;
			str.replace(a, buf.length(), buf);
		}
	}
	return 0;
}