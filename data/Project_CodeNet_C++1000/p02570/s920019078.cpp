#include <iostream>
using namespace std;

int main() {
	long long d,t,s;
	cin >> d >> t >> s;
	long long dd=s*t;
	if(dd>=d)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}