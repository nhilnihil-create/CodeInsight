//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	int		a,b,c,d,i,j,k,n,m,x,y,ans = 0;
	cin >> n;
	vector<vector<int>>	ab(n+1);
	vector<int> A(n+1),B(n+1);
	for(i=0;i<n-1;i++) {
		cin >> a >> b;
		ab[a].push_back(b);
		ab[b].push_back(a);
		A[i] = a;
		B[i] = b;
	}
	for(i=1;i<=n;i++) {
		ans = max(ans , (int)ab[i].size());
	}
	queue<int> que;
	map<ll,int> hen;
	set<int> tmp;
	que.push(1);
	while(!que.empty()) {
		c = que.front();
		que.pop();
		tmp.clear();
		//cout << "c:"<< c << endl;
		for(j=0;j<ab[c].size();j++) {
			ll key;
			d = ab[c][j];
			if (c > d) key = (ll)d*1000000 + c;
			else key = (ll)c*1000000 + d;
			//cout << "key:" << key << endl;
			if (hen.count(key)) tmp.insert(hen[key]);
		}
		x = 1;
		for(j=0;j<ab[c].size();j++) {
			ll key;
			d = ab[c][j];
			if (c > d) key = (ll)d*1000000 + c;
			else key = (ll)c*1000000 + d;
			if (!hen.count(key)) {
				while(tmp.count(x)) x++;
				hen[key] = x;
				//cout << key << " " << x << " " << j << endl;
				tmp.insert(x++);
				que.push(d);
			};
		}
	}
	cout << ans << endl;
	for(i=0;i<n-1;i++) {
		ll key;
		c = A[i]; d = B[i];
		if (c > d) key = (ll)d*1000000 + c;
		else key = (ll)c*1000000 + d;
		cout << hen[key] << endl;
	}

	return 0;
}
