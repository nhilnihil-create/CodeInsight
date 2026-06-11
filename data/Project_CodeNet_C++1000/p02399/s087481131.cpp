#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	long long int a, b;
	cin >> a >> b;

	int result;
	int mod;
	double precisionNum;
	result = a / b;
	mod = a % b;
	precisionNum = double(a) / double(b);

	cout << result << " " << mod << " " ;
	printf("%.5f\n", precisionNum);
	//system("pause");
	return 0;
}