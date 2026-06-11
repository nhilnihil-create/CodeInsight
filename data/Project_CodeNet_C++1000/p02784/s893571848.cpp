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
	//int h, a;
	//cin >> h >> a;
	//int ans;
	//ans = h / a;
	//if (h - ans*a == 0) {}
	//else { ans += 1; }
	//cout << ans;

	int h, n;
	cin >> h >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		h -= a;
		if (h <= 0) { cout << "Yes"; exit(0); }
	}
	cout << "No";
}

