#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)



int main()
{
	long double x;
	cin >> x;
	long double p;
	p = x / 3;
	cout <<fixed<< setprecision(10)<< pow(p, 3) << "\n";
	return 0;
}