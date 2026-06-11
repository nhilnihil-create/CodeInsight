#include <iostream> // ?¨??????\??????

using namespace std;

int main() {
	int row = 9;	// ???
	int col = 9;	// ???
	for (size_t i = 1; i <= row; i++)
	{
		for (size_t j = 1; j <= col; j++)
		{
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}