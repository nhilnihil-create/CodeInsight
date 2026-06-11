#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef vector<vint> vvint;

static int n, x, t;

int main()
{
	while(cin >> n >> x >> t){
		cout << int(ceil(n/double(x))) * t << "\n";
	}
	
	return 0;
}
