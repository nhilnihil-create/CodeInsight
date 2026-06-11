#include<iostream>
using namespace std;
int main() {

	string hi;
	cin >> hi;
	int i;
	int flag = 0;
	for (i = 0; i < hi.length(); i++) {
		if (hi[i] == 'h') {
			if (flag == 0) {
				flag = 1;
			}
			else {
				cout << "No\n";
				return 0;
			}
		}else if(hi[i] == 'i'){
			if (flag == 1) {
				flag = 0;
			}
			else {
				cout << "No\n";
				return 0;
			}
		}
		else {
			cout << "No\n";
			return 0;
		}

	}
	if (flag == 1) {
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
	}
	return 0;

}