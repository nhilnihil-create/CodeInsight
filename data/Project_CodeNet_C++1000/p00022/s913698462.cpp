#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> r;
	while (true)
	{
		scanf("%d", &n);
		if (n==0)break;
		int max=-2147483648,now=0,in=0;
		for (int i=0; i<n; i++)
		{
			cin >> in;
			now += in;
			if (now > max) max=now;
			if (now < 0) now=0;
		}
		r.push_back(max);
	}
	for (int i=0; i<r.size(); i++)
	{
		cout << r[i] << endl;
	}
	return 0;
}