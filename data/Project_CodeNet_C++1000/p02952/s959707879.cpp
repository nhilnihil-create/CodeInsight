#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int out = 0;
	for(int i = 1; i <= n; i++){
		out += to_string(i).size() % 2;
	}
	cout << out << endl;
}
