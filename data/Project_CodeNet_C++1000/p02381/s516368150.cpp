#include<cmath>
#include<iomanip>
#include<iostream>

using namespace std;

int main() {
	int count;
	bool inputOver = false;
	while (!inputOver) {
		cin >> count;
		if (count) {
			int *list = new int[count];
			double sum = 0.0;
			for (int i = 0; i < count; i++) {
				int temp;
				cin >> temp;
				list[i] = temp;
				sum += temp;
			}

			double mid = sum/count;
			sum = 0.0;
			
			for (int i = 0; i < count; i++) {
				sum += pow(list[i] - mid, 2);
			}
			sum = sum / count;
			cout.setf(ios::fixed);
			cout << setprecision(8) << sqrt(sum) << endl;

			delete[] list;
		}
		else {
			inputOver = true;
			break;
		}

	}


	return 0;
}