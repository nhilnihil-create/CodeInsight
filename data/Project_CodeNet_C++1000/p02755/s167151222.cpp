#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int A,B;
	cin >> A >> B;
	for (int i = 1; i <= 1500; ++i)
	{
		int tax8 = i * 8 / 100, tax10 = i * 10 / 100;
		if (tax8 == A && tax10 == B)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}