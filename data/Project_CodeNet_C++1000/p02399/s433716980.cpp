#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	cout << int(a/b) << " " << (a % b) << " " << fixed << (double)a / (double)b << endl;
	
	return 0;
}