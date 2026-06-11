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
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;


int main()
{
	int n; cin >> n;
	vector<int> aa(n);
	rep(i, n) cin >> aa[i];
	sort(aa.begin(), aa.end());
	cout << aa[n / 2] - aa[n / 2-1];
}
