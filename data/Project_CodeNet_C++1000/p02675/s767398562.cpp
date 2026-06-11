#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string N;
	cin >> N;

	int one = N.length() - 1;
	if (N[one] == '2' || N[one] == '4' || N[one] == '5' || N[one] == '7' || N[one] == '9') {
		cout << "hon" << endl;
	}
	else if (N[one] == '0' || N[one] == '1' || N[one] == '6' || N[one] == '8') {
		cout << "pon" << endl;
	}
	else if (N[one] == '3') {
		cout << "bon" << endl;
	}


}




