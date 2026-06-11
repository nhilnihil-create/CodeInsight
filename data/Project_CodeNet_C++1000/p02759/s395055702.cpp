#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int paper;
	if (N % 2 == 0) paper = N / 2;
	else paper = N / 2 + 1;
	cout << paper << endl;
	return 0;
}