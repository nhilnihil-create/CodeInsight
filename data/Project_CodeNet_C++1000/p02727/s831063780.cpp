#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;
int main()
{
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<int> p(a);
	vector<int> q(b);
	vector<int> r(c);
	rep(i,a) cin>>p[i];
	rep(i,b) cin>>q[i];
	rep(i,c) cin>>r[i];
	sort(p.begin(),p.end(),greater<int>());
	sort(q.begin(),q.end(),greater<int>());
	for(int i = 0; i < x; i++){
		r.push_back(p[i]);
	}
	for(int i = 0; i < y; i++){
		r.push_back(q[i]);
	}
	sort(r.begin(),r.end(),greater<int>());
	ll ans = 0;
	for(int i = 0; i < (x+y); i++){
		ans += r[i];
	}
	cout<<ans<<endl;
	return 0;
}

