#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
#define ll long long
#define bl bool
#define nn printf("\n");
#define mod 1000000007

using namespace std;

vector<bool> era(1000010, true);
void makePrimeTable(int n)
{
	era[0] = false; era[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (era[i]) { for (int j = i * 2; j <= n; j += i) { era[j] = 0; } }
	}
}
int main()
{
	makePrimeTable(1000000);
	while (1)
	{
		int n = 0; cin >> n;
		if (n == 0) { break; }
		int num = 0;
		for (int i = n + 1; i < 2 * n; i++)
		{
			if (era[i]){ num += 1; }
		}
		if (n == 1) { num += 1; }
		printf("%d\n", num);
	}
}