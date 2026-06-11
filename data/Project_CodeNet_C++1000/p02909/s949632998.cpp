#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long


int main()
{
	string S;
	cin >> S;
	string ans[] = { "Sunny","Cloudy","Rainy","Sunny" };
	for (int i = 0; i < 4; i++) {
		if (S == ans[i]) {
			cout << ans[i + 1] << endl;
			return 0;
		}
	}
}
