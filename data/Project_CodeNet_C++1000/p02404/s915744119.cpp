#include<iostream>
#include<algorithm>
using namespace std;

void foutput(int aa, int bb) {
	for (int i = 0; i < aa; i++){
		if (i == 0 || i == aa - 1) {
			for (int n = 0; n < bb; n++){
				cout << "#";
			}
		}else {
			cout << "#";
			for (int m = 0; m < bb-2; m++){
				cout << ".";
			}
			cout << "#";
		}
		cout << endl;
	}
}

int main() {
	int frame[2][10000];
	int a, b ,length;
	for (int i = 0; ; i++){
		cin >> a >> b;
		if (a==0||b==0){
			length = i;
			break;
		}
		frame[0][i] = a;
		frame[1][i] = b;
	}
	for (int i = 0; i < length; i++){
		foutput(frame[0][i],frame[1][i]);
		cout << endl;
	}
	cin >> length;
}