#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int s;
	cin >> s;
	int second = s % 60;
	int minute = s % 3600 / 60;
	int hour = s / 3600;
	cout << hour << ":" << minute << ":" << second << endl;
}
