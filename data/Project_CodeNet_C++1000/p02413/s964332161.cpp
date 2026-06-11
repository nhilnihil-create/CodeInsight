#include <iostream>

using namespace std;

int main()
{
	int r, c, element;
	int sum_line = 0, sum_all = 0, sum_colum[100] = { 0 };
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> element;
			cout << element << " ";
			sum_line += element;
			sum_colum[j] += element;
		}
		cout << sum_line << endl;
		sum_all += sum_line;
		sum_line = 0;
	}
	for (int i = 0; i < c; i++) {
		cout << sum_colum[i] << " ";
	}
	cout << sum_all << endl;
	return 0;
}