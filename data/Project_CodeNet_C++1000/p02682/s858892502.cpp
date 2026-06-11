#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a, b, c, k, total=0;
	cin >> a >> b >> c >> k;
	total += min(a, k);
	k -= min(a, k);
	k -= min(b, k);
	total += k*-1;
	cout << total;
}

