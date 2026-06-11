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
	int maxi = -100000;
	int count = 0;
	int ans = 0;
	vector<unsigned long long int> H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		unsigned long long int t;
		cin >> t;
		H.push_back(t);
	}
	for (int i = 0; i < N - 1; i++) {
		if (H[i] < H[i + 1]) {
			count = 0;
		}
		else
			count++;
		ans = max(ans, count);
	}

	cout << ans << endl;
	return 0;
}