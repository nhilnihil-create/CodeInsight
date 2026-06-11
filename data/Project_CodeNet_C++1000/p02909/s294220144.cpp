#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	if (S == "Sunny") {
		cout << "Cloudy" << endl;
	}
	else if (S == "Cloudy") {
		cout << "Rainy" << endl;
	}
	else if (S == "Rainy") {
		cout << "Sunny" << endl;
	}
	
}
