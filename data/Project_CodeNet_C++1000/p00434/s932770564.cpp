#include <iostream>

using namespace std;

int main()
{
	int m[28], f;
	bool b[30];
	for (int i = 0; i < 30; ++i) {
		b[i] = false;
	}
	for (int i = 0; i < 28; ++i) {
			cin >> m[i];
			b[m[i]-1] = true;
		}
	for (int i = 0; i < 30; ++i) {
		if (!b[i])cout << i+1 <<endl;
	}

    return 0;
}