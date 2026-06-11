#include<iostream>
#include<string>
using namespace std;

int main() {
	int a=0;
	string q;
	cin >> q;
	int w = q.length();
	/*cout << w;
	cout << q[w-1];
	char c = q[w-1];
	cout << c;*/
	if ( q[w - 1] == '2' || q[w - 1] == '4' || q[w - 1] == '5' || q[w - 1] == '7' || q[w - 1] == '9') {
		cout << "hon";
	}
	else if (q[w-1] == '3') {
		cout << "bon";
	}
	else {
		cout << "pon";
	}
}