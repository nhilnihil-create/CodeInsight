#include <bits/stdc++.h>
using namespace std;

int main()
{
	string N;
	cin >> N;
	
	int digitSum = 0;
	for(int i = 0; i < (int)(N.length()); i++)
		digitSum += (N[i] - '0');
		
	if(digitSum % 9 == 0)
		printf("Yes");
		
	else
		printf("No");
}
