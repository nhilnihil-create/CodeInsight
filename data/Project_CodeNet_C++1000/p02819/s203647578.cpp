#include<iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include<limits>
#include<cstdlib>
#include<functional>
#include<cassert>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
//#include <bits/stdc++.h>//atcoderでsqrtを使うときに必要
#define fi(p) for(int i=0;i<(p);i++)
#define ce(d) cout<<d<<endl;
#define ll long long
#define sorts(c) sort((c).begin(),(c).end());

using namespace std;

bool sosu(ll num)
{

	if (num == 2) {
		return true;
	}
	else if (num % 2 == 0) {
		return false;
	}

	double sq = sqrt(num);
	for (int i = 3; i <= sq; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}
	return true;


}

void solve() {
	ll a,b,k;
	cin >> a;

	bool judge = false;
	while (judge==false) 
	{
		judge = sosu(a);
		a++;
	}

	ce(a-1);

	
}




int main()
{
	solve();

	int a;//止める用
	cin >> a;
	return 0;
}