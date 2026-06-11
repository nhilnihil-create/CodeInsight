//#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<map>
#include<set>
#include<limits.h>
#include<list>
#include <cassert>
#include<sstream>
#include<locale>
#include <bitset>
using namespace std;
using ll = long long int;

int main() {
	long long  n, ans;
	cin >> n;
	for(int i=sqrt(n);i>0;--i)
		if (n % i == 0)
		{
			cout << (i + (n / i) - 2) << endl;
			break;
		}
	return 0;
} 



