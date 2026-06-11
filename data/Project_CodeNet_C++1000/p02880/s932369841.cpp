#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	unordered_set<int> niz;

	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			niz.insert(i * j);

	if (niz.find(n) != niz.end())
		cout << "Yes";
	else cout << "No";
}