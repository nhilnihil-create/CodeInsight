#include <iostream>
using namespace std;

int main()
{
	int N, back;
	N = 0; back = 0;
	cin >> N;
	if (N > 0 && N<=10000) {
		back = N % 1000;
		if (back == 0) {
			cout << "0" << endl;
		}
		else {
			cout <<1000 - back << endl;

		}
	}
	return 0;
}