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
	string day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };


	for (int i = 0; i < 7; i++) {
		if (day[i] == S) {
			cout << 7 - i << endl;
		}
	}
	
}
