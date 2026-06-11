#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std;


int main() {
	int a, b;
	cin >> a >> b;
	cout << fixed << setprecision(8) << a / b << " " << a % b << " " << 1.0 * a / b << "\n";
}