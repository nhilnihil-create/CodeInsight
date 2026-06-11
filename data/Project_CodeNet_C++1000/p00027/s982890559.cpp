#include <iostream>
using namespace std;


int main()
{
	int m, d;
	while (cin >> m >> d, m || d){
		int day = 0;
		for (int i = 1; i < m; i++){
			if (i == 2){
				day += 29;
			}
			else if (i == 4 || i == 6 || i == 9 || i == 11){
				day += 30;
			}
			else{
				day += 31;
			}
		}
		day += d;
		if (day % 7 == 1){
			cout << "Thursday" << endl;
		}
		else if (day % 7 == 2){
			cout << "Friday" << endl;
		}
		else if (day % 7 == 3){
			cout << "Saturday" << endl;
		}
		else if (day % 7 == 4){
			cout << "Sunday" << endl;
		}
		else if (day % 7 == 5){
			cout << "Monday" << endl;
		}
		else if (day % 7 == 6){
			cout << "Tuesday" << endl;
		}
		else{
			cout << "Wednesday" << endl;
		}
	}
	return 0;
}