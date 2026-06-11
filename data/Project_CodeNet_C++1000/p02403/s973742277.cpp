#include <iostream>
using namespace std;

int main()
{
	int h = 0, w = 0;

	cin >> h >> w;

	while ((h != 0) | (w != 0)) {
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++)
				cout << "#";
			cout << endl;
		}
		cout << endl;
		cin >> h >> w;
	}

    return 0;
}