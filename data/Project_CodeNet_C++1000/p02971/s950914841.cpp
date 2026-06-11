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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> sa(n);
	sa = a;
	sort(sa.begin(), sa.end());
	reverse(sa.begin(), sa.end());
	rep(i, n) {
		if (a[i] == sa[0])
		{
			cout << sa[1]<<endl;
			
		}
		else
			cout << sa[0]<<endl;
	}

}
