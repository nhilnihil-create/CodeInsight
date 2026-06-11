#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;

	int x = N % 2;
	int y = N / 2;

	cout << x + y << endl;
}