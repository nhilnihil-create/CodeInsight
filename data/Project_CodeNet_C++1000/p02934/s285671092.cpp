#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int n;
	cin >> n;
	vector<double> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	vector<double> b(n);
	for(int i=0;i<n;i++) b[i] = 1 / a[i];
	double p, q;
	p = 0;
	for(int i=0;i<n;i++) p += b[i];
	q=1/p;
	cout << q << "\n";


	return 0;
}