#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	vector<int> Vec(100);
	int n;
	while(cin >> n)
	{
		++Vec[n];
	}
	int max = 0;
	for(int i = 0; i < Vec.size(); ++i)
	{
		if(max < Vec[i])
		{
			max = Vec[i];
		}
	}
	for(int i = 0; i < Vec.size(); ++i)
	{
		if(max == Vec[i])
		{
			cout << i << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}