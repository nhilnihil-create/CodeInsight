#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;
 
#define PI 3.14159265358979323846264338327950L
 
int main() {
	long long A, B, N;
	cin >> A >> B >> N;

	long long x;
	if (B - 1 <= N) {
		x = B - 1;
	} else {
		x = N;
	}
	long long max = (A * x) / B - A * (x / B);
	cout << max << endl;
}