#include <iostream>
#include <vector>

using namespace std;

bool isSumExist(vector<int>& A, int pos, int digit)
{	
	if (digit == 0)
	{
		return(true);
	}
	if (pos >= A.size() || digit < 0)
	{
		return(false);
	}
	return(isSumExist(A, pos + 1, digit - A[pos]) || isSumExist(A, pos + 1, digit));
}

void solve()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int m;
		cin >> m;
		if(isSumExist(A, 0, m))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}