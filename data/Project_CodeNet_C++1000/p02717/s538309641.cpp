#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int a, b, c, tmp;
	cin >> a >> b >> c;
	tmp=a;
	a=b;
	b=tmp;
	tmp=a;
	a=c;
	c=tmp;
	cout << a << ' ' << b << ' ' << c;
}

