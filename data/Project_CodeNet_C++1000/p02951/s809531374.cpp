#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int A, B,C;
	cin >> A >> B >> C;

	int nokori = A - B;
	int sss= C - nokori;

	if (sss <= 0)
	{
		cout << 0;
	}
	else
	{
		cout << sss;
	}
	
}
