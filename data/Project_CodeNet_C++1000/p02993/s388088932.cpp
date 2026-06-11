#include<bits/stdc++.h>
using namespace std;

int main()
{

	string sh;
	cin >> sh;
	if (sh[0] == sh[1] || sh[1] == sh[2] || sh[2] == sh[3])
	{
		printf("Bad\n");
	}
	else
	{
		printf("Good\n");
	}
	return 0;
}