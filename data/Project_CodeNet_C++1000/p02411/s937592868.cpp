#include<iostream>
#include<string>
using namespace std;

int main()
{
	int m = 0, f = 0, r = 0, count = 0;
	string grade[100];
	while (1){
		cin >> m >> f >> r;
		if (m == -1 && f == -1 && r == -1) break;
		if (m == -1 || f == -1)                             grade[count++] = "F";
		else if (m + f >= 80)                               grade[count++] = "A";
		else if (m + f >= 65)                               grade[count++] = "B";
		else if ((m + f >= 50) || (m + f >= 30 && r >= 50)) grade[count++] = "C";
		else if (m + f >= 30)                               grade[count++] = "D";
		else                                                grade[count++] = "F";
	}
	for (int i = 0; i < count; i++) cout << grade[i] << endl;
	return 0;
}