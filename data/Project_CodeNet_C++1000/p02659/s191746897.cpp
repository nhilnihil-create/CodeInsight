#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;


int main() {
	long long a;

	string b;
	
	cin >> a >> b;

	int bb = 100*(b[0]-'0') + 10*(b[2]-'0') + (b[3]-'0');
	
	long long ans = a * bb;

	cout << ans/100 << endl;

	return 0;

}
