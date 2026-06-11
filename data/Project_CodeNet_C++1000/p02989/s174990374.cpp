#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	int N;
	int prev = 0, target = 0;
	int t = 0;
	int count = 0;
	cin >> N;
	vector<int> d;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		d.push_back(t);
	}

	sort(d.begin(), d.end());
	int mid = 0;
	mid = (N / 2)-1; //mid left
	prev = d[mid];
	target = d[mid + 1];
	if (d[mid] == d[mid + 1])
		cout << 0 << endl;
	else {
		while (prev != target) {
			prev++;
			count++;
		}
		cout << count << endl;
	}

	return 0;
}