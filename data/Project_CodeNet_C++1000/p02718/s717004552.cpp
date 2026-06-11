#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	auto a = vector<int>(n);
	int total = 0;
	for(auto&& aa : a){
		cin >> aa;
		total += aa;
	}
	sort(a.begin(), a.end(), greater<int>());
	cout << (a[m - 1] * 4 * m < total ? "No" : "Yes") << endl;
	return 0;
}
