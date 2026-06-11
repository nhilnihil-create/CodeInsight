#include<iostream>

using namespace std;

int main() {
	bool inputOver = false;
	char result = 'A';
	while (!inputOver) {
		int m, f, r;
		cin >> m >> f >> r;
		int sum = m + f;
		if (m == -1 && f == -1 && r == -1) {
			inputOver = true;
			break;
		}else{
			if (m==-1||f==-1) {
				result = 'F';
			}
			else if (sum>=80) {
				result = 'A';
			}
			else if (sum>=65&&sum<80)
			{
				result = 'B';
			}
			else if (sum >= 50 && sum<65)
			{
				result = 'C';
			}
			else if (sum >= 30 && sum<50)
			{
				result = 'D';
				if (r >= 50)
					result = 'C';
			}
			else if (sum < 30) {
				result = 'F';
			}

			cout << result << endl;
		
		}
	}

	//system("pause");
	return 0;
}