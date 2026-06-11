#include <iostream>
using namespace std;

int main()
{
	int distance, time, speed;
	cin >> distance >> time >> speed;
	if(time*speed>=distance)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}