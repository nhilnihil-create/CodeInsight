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
	for(int i = 1; i < n+1; i++)
	{
		if (to_string(i).length() == 1 || to_string(i).length() == 3 || to_string(i).length() == 5)
		{
			ans++;
		}
	}
	cout << ans<< endl;
	return 0;
}