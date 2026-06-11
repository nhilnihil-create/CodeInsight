#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[4][4];
bool tag[4][4];
bool check() {
	for (int i = 1; i <= 3; i++) {
		if (tag[i][1] && tag[i][2] && tag[i][3])
			return true;
	}	
	for (int i = 1; i <= 3; i++) {
		if (tag[1][i] && tag[2][i] && tag[3][i])
			return true;
	}
	if (tag[1][1] && tag[2][2] && tag[3][3]) {
		return true;
	}
	if (tag[3][1] && tag[2][2] && tag[1][3]) {
		return true;
	}
	return false;
}
void in(int b) {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (b == a[i][j])
				tag[i][j] = true;
		}
	}
}
int main() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	int n;
	int b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		in(b);
	}
	if (check()) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}