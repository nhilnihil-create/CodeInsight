#include <bits/stdc++.h>
using namespace std;

int main()
{
	int day[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < 12; i++) {
		day[i] += day[i - 1];
	}
	int mo, da;
	while (cin >> mo >> da, mo | da) {
		switch ((day[mo - 1] + da - 1) % 7)
		{
		case 0:
			cout << "Thursday" << endl;
			break;
		case 1:
			cout << "Friday" << endl;
			break;
		case 2:
			cout << "Saturday" << endl;
			break;
		case 3:
			cout << "Sunday" << endl;
			break;
		case 4:
			cout << "Monday" << endl;
			break;
		case 5:
			cout << "Tuesday" << endl;
			break;
		case 6:
			cout << "Wednesday" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}