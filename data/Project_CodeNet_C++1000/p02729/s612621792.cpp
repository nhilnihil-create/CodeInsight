#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int c2(int n) {
	return n*(n - 1) / 2;
}



int main()
{
	int n, m;
	cin >> n >> m;
	cout << c2(n) + c2(m);
	
}