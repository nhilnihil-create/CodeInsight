#include<iostream>
using namespace std;
int main()
{
	int x,a,b,c;
	cin >> x;
	a = x / 3600;
	x = x % 3600;
	b = x / 60;
	x = x % 60;
	c = x;
	cout << a <<":"<<b<<":"<<c<< endl;
	return 0;
}