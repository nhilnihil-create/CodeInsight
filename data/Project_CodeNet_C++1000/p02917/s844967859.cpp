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
int main()
{
	int sum = 0;
	int n; cin >> n;
	vector<int> b(n - 1);
	vector<int> a(n);
	rep(i, n - 1) cin >> b[i];
	for (int i = 0;i < n;i++) {
		if (i == 0) //最初
			a[i] = b[i];
		else if(i==n-1){//最後
			a[i] = b[i - 1];
		}
		else {
			a[i] = min(b[i - 1], b[i]);
		}
	}
	rep(i, n) sum += a[i];
	cout << sum;
}
