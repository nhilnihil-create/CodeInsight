#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long int X;
	cin >> X;

	long long int mon500 = int(X / 500);
	X -= mon500 * 500;

	long long int mon5 = int(X / 5);
	long long int happy = 1000 * mon500 + 5 * mon5;

	cout << happy;

}