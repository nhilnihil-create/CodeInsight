#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>

using ll = long long;

using namespace std;
int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> qq(q);
	vector<int>pt(n, k - q);
	for (int i = 0;i < q;i++) { //round
		int s; cin >> s;
		//-1してptにいれる
		pt[s - 1]++;
	}
	for (int i = 0;i < n;i++) { 
		if (pt[i] > 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}


