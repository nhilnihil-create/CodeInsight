#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double n;
	cin >> n;
	int need = (n + 1) / 2;
	cout << fixed << setprecision(7) << need / n;
}
