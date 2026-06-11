#include <iostream>

using namespace std;

int main(){
	long long int h, w;
	cin >> h >> w;

	if(h == 1 || w == 1)
		cout << "1";
	else if(h * w % 2 == 0)
		cout << h * w / 2;
	else
		cout << (h * w + 1) / 2;
}