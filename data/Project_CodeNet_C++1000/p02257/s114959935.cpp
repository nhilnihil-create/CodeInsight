#include <iostream>
#include<math.h>

using namespace std;

int couent = 0;
int keisann(int a) {
	if (a == 2) { couent++; }
	if (a % 2 == 0) { return 0; }
	int v = sqrt(a);
	for (int i = 3; i <= v; i+=2)
	{
		if (a%i == 0) {
			return 0;
		}
	}
	couent++;
}
int main()
{
	int dataset;
	cin >> dataset;
	for (size_t i = 0; i < dataset; i++)
	{
		int a;
		cin >> a;
		keisann(a);
	}
	cout << couent << endl;
}