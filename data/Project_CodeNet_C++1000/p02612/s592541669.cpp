#include <iostream>
using namespace std;
int main()
{
	int N, i;
	cin >> N;
	i = 0;
	while (N > 1000 * i) {
		i++;
	}
	cout << 1000 * i - N;
}