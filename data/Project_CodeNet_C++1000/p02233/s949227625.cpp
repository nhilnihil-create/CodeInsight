#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	vector<int> fibo;
	fibo.push_back(1);
	fibo.push_back(1);
	for (int i = 2; i <= 44; ++i)
	{
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}
	int n;
	cin >> n;
	cout << fibo[n] << endl;
}

int main()
{
	solve();
	return(0);
}