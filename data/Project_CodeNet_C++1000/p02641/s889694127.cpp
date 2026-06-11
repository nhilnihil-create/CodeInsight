#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int x, n;
	cin >> x >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	vector<int> q(n);
	rep(i, n)
	{
		q[i] = p[i] - x;
	}

	int ans, a;
  a=0;
	int count = 0;
	bool tf = false;
	rep(i, n+1)
	{
		if (i % 2 == 0) a = i / 2;
		else a = -(i + 1) / 2;
		count=0;
		rep(t, n)
		{
			if (a != q[t])
			{
				count++;
			}
        } 
		if (count == n)
		{
				tf = true;
		}
		
		if (tf) break;
	}

  
	cout << a + x << "\n";


	return 0;
}