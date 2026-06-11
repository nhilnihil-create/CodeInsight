// String - Equivalence.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int

void helper(int i, int n, char a, char out[])
{

	if (i == n)
	{

		out[i] = '\0';
		cout << out << endl;
		return;

	}


	for ( char ch = 'a' ; ch <= a; ch++ )
	{
		out[i] = ch;
		if (ch == a)
		{
			helper(i + 1, n, a + 1, out);
		}
		else
		{
			helper(i + 1, n, a, out);
		}

	}





}





int main() {
//	fastIO


	int n;
	cin >> n;
	char out[100];


	helper(0, n, 'a', out);



	return 0;
}