#include <iostream>

using namespace std;

int x, y;

int main(){
	cin >> x >> y;
	cout << max(0, x - 2 * y);
}	