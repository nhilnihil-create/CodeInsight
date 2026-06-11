#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#define long long ll
using namespace std;
int main()
{
	//int a, b, c;
	//cin >> a >> b >> c;
	//if (a == b)
	//{
	//	if (a != c)
	//	{
	//		cout << "Yes";
	//		exit(0);
	//	}
	//	else cout << "No";
	//}
	//else if (a == c)
	//{
	//	if (a != b)cout << "Yes";
	//	else cout << "No";
	//}
	//else if (b == c)
	//{
	//	if (b != a)cout << "Yes";
	//	else cout << "No";
	//}
	//else cout << "No";

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a % 2 == 0)
		{
			//cout << a<<" ";
			if (a % 3 != 0 && a % 5 != 0) {
				cout << "DENIED";
				exit(0);
			}
 
		}
	}
	cout << "APPROVED";
}

