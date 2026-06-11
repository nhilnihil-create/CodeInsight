#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define int long long
using namespace std;

signed main() {
	int a, b;
	while (cin >> a >> b, a | b) {
		for (int c = 0; c < a; c++) {
			for(int d=0;d<b;d++)cout<<"#";
			cout << endl;
		}
		cout << endl;
	}
}