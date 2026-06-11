#include<iostream>
using namespace std;
using LL = long long;

int main() {
	LL N;
	cin >> N;
	LL t1 = N / 500;
	LL t2 = (N % 500) / 5;
	cout << t1 * 1000 + t2 * 5 << endl;
	return 0;
}