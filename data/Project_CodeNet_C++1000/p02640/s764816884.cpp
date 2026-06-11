#include <iostream>
using namespace std;
int main(){
	int x,y,a=0;
	cin >> x >> y;
	for (int i = 0; i <= x;i++)
		if (i * 4 + (x - i) * 2 == y)
			a++;
	if (a == 0)
		cout << "No";
	else
		cout << "Yes";
}