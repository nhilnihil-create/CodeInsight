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
	//int n, m;
	//cin >> n >> m;
	//if (n == m)cout << "Yes";
	//else cout << "No";

	//int a;
	//int b;
	//cin >> a >> b;
	//
	//if (a > b)
	//	for (int i = 0; i < a; i++)
	//		cout << b;
	//else
	//	for (int i = 0; i < b; i++)
	//		cout << a;

	int a,ans = 1,min;
	cin >> a >> min;
	for (int i = 1; i < a; i++) {
		int x;
		cin >> x;
		if (x < min) ans++, swap(x, min);
	}
	cout << ans << endl;


}

