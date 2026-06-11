#include<iostream>
using namespace std;
int H, A;
int i = 0;
int main() {
	cin >> H;
	cin >> A;
	while (H > 0)
	{
		H = H - A;
		i++;
	}
	cout << i;
	return 0;
}