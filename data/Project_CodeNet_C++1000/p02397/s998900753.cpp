#include<iostream>
using namespace std;

#define swap(type, x, y) do{ type tmp = x; x = y; y = tmp; } while(0)

int main()
{
	int x = 0, y = 0, count = 0, a[6000] = { 0 };
	while (1){
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		if (x > y) swap(int, x, y);
		a[count] = x, a[count + 1] = y;
		count += 2;
	}
	for (int i = 0; i < count; i += 2) cout << a[i] << " " << a[i + 1] << endl;
	return 0;
}