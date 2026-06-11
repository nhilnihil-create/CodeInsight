#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << (N - (N%2 == 0)) / 2 << endl;
}
