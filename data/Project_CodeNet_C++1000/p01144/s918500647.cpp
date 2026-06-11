
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>


using namespace std;


bool solve(int n, int m){
	vector<pair<int,int> > d(n);
	for(int i=0;i<n;i++){
		cin>> d[i].second>> d[i].first;
	}
	
	sort(d.rbegin(), d.rend());
	int ans = 0;
	for(int i=0;i<d.size();i++){
		int a = min(d[i].second, m);
		d[i].second -= a;
		m -= a;
		ans += d[i].first * d[i].second;
	}
	
	cout<< ans<< endl;

	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	int n, m;
	while(cin>>n>>m, !(n==0 && m==0)){
		solve(n,m);
	}
	return 0;
}

 