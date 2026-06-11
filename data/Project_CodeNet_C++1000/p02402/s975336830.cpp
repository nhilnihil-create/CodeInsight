#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,count_max,count_min,temp;
	long long sum = 0;
	cin >> n;

	rep(i,n)
	{
		cin >> temp;
		if(i == 0)
		{
			count_max = count_min = temp;
		}
		else
		{
			count_max = max(count_max,temp);
			count_min = min(count_min,temp);
		}
		sum += temp;
	}

	cout << count_min << " " << count_max << " " << sum << endl;

	return 0;
}