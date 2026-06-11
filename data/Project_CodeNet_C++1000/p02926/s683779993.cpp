#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
	cin.tie(0); ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	int x, y;
	vector< pair<double, pair <ll, ll>>> pt(n);
	
	for(int i = 0; i< n; i++){
		cin >> x >> y;
		double ang = 0;
		if(x == 0 && y == 0) ang = 0;
		else ang = atan2(x, y);
		pt[i] = {ang, {x, y}};
	}
	sort(pt.begin(), pt.end());
	double ans = 0;
		for(int i = 0; i < n; i++){
		ll sumx = 0, sumy = 0;
		for(int j = i; j < i + n; j++){
			sumx += pt[j%n].second.first;
			sumy += pt[j%n].second.second;
			ans = max(ans, sqrt(sumx * sumx + sumy * sumy));
		}
	}
  	/**/
	printf("%.20f\n", ans);
	/**/
	/**/
}