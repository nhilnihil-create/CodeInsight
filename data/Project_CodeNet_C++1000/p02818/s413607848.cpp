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



void solve() {
	ll a,b,k;
	cin >> a >> b >>k;

	if (k <= a) {
		ce(a - k);
		ce(b)
	}
	else {
		ce(0);
		if (b + a - k < 0) {
			ce(0);
		}
		else {
			ce(b + a - k)
		}
	}

	
}

int main()
{
	solve();

	int a;//止める用
	cin >> a;
	return 0;
}