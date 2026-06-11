#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;
struct dog {
	string a;
	int b;
};
int main()
{
	int h, a;
	cin >> h >> a;
	int ans;
	ans = h / a;
	if (h - ans*a == 0) {}
	else { ans += 1; }
	cout << ans;
}

