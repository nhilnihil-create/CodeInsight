#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int n;cin >> n;
	vector<pair<int,int>> ab(n);
	rep(i,n)
	{
		int foo,fooo;
		cin >> foo >> fooo;
		ab[i] = make_pair(foo,fooo);
	}
	pair<int,int> v;

	int ma=0;
	rep(i,n)
	{
		rep(j,n)
		{
			if(i==j)continue;
			v.first = ab[i].first-ab[j].first;
			v.second = ab[i].second - ab[j].second;
			int c=0;
			//cout<<v.first<<':'<<v.second<<endl;
			rep(ii,n)
			{
				pair<int,int> vv;
				vv.first = ab[ii].first+v.first;
				vv.second = ab[ii].second+v.second;
				rep(jj,n)
				{
					if(vv==ab[jj])c++;
				}
			}
			ma = max(ma,c); 
		}
	}

	cout<<n-ma<<endl;
	return 0;
}