#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long i;
	int building;
	int floor;
	int room_number;
	int visiter[4][3][10] = {0};
	for (i = 0; i < n; i++) {
		int Visiter;
		cin >> building >> floor >> room_number >> Visiter;
		visiter[building - 1][floor - 1][room_number - 1] += Visiter;
	}
	for (i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				cout << setw(2) << visiter[i][j][k];
			}
				cout << endl;
		}
		if (i == 3) break;
		cout << "####################" << endl;
	}
	return 0;
}