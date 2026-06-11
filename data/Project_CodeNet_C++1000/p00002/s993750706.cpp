#include<iostream>
#include<utility>
#include<climits>
using namespace std;

int main()
{
	int a, b;

	while(cin >> a >> b)
	{ 

	int sum = a + b;

	int keta;

	if (sum / 1000000 >= 1) keta = 7; 
	else if (sum / 100000 >= 1) keta = 6; 
	else if (sum / 10000 >= 1) keta = 5; 
	else if (sum / 1000 >= 1) keta = 4; 
	else if (sum / 100 >= 1) keta = 3; 
	else if (sum / 10 >= 1) keta = 2;
	else keta = 1;

	cout << keta << endl;

	}

	return 0;
}