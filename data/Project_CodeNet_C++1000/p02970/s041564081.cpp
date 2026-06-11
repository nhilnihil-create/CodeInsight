#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double n, d;
	cin >> n >> d;
	double honsuu = 2 * d + 1;
	cout << ceil(n / honsuu) << endl;
}