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
	int n,m;
	cin>>n>>m;
	priority_queue<double> q;
	for(int i = 0; i < n; i++){
		double num;
		cin>>num;
		q.push(num);
	}
	for(int i = 0; i < m; i++){
		double topNum = q.top();
		topNum = topNum * 0.5;
		q.pop();
		q.push(topNum);
	}
	ll ans = 0;
	while( !q.empty()){
		ans += floor(q.top());
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}

