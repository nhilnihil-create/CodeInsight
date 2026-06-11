#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;
//	std::cout<<std::fixed<<std::setprecision(10);

int main() {
	ll T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	string inf = "infinity";

	ll dist[2] = {T1*(A1-B1), T2*(A2-B2)};
	if(dist[0]>0) {
		dist[0] *= -1;
		dist[1] *= -1;
	}
	//cout << dist[0] << ' ' << dist[1] << endl;

	if(dist[0]+dist[1]==0) {
		cout << inf << endl;
	} else if(dist[0]+dist[1]<0) {
		cout << 0 << endl;
	}else {
		ll ans = 2*((-dist[0])/(dist[0]+dist[1]))+1;
		if((-dist[0])%(dist[0]+dist[1])==0) ans--;
		cout << ans << endl;
	}

	return 0;
}