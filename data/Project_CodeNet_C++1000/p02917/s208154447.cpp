#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979


int main()
{
	int n, ans = 0;
	cin >> n;
	vector<int>b(n-1);
	vector<int>a(n);
	rep(i, n - 1) cin >> b[i];
	
	ans += b[0];
	ans += b[n - 2];
	for (int i = 1; i < n - 1; i++) ans += min(b[i - 1], b[i]);
	cout << ans;
	return 0;
}