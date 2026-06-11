#include<iostream>
using namespace std;
int a[100000], b[100000];
int main() {
	
	int A, B, M;
	int x, y, c;
	cin >> A >> B >> M;
	int i;
	int amin = 100001, bmin = 100001, MIN = 200002;
	for (i = 0; i < A; i++) {
		cin >> a[i];
		if (a[i] < amin)amin = a[i];
	}
	
	for (i = 0; i < B; i++) {
		cin >> b[i];
		if (b[i] < bmin)bmin = b[i];
	}

	MIN = amin + bmin;

	for (i = 0; i < M; i++) {
		cin >> x >> y >> c;
		if (a[x - 1] + b[y - 1] - c < MIN)MIN = a[x - 1] + b[y - 1] - c;
	}

	cout << MIN << endl;
	return 0;
	//A
	/*
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
	return 0;*/

}