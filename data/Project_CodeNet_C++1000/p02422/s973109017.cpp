#include <iostream>
#include <string>
using namespace std;

string str;
int q;

int main(){
	cin >> str >> q;
	string od, rp;
	int a, b;
	for (int I = 0; I < q; I++) {
		cin >> od >> a >> b;
		if (od == "print") {
			for (int i = a; i <= b; i++) {
				cout << str[i];
			}
			cout << endl;
		}
		else if (od == "reverse") {
			int c = (b - a + 1) / 2;
			for (int i = 0; i < c; i++) {
				char r = str[a + i];
				str[a + i] = str[b - i];
				str[b - i] = r;
			}
		}
		else if (od == "replace") {
			cin >> rp;
			for (int i = a; i <= b; i++) {
				str[i] = rp[i- a];
			}
		}
	}

	return 0;
}