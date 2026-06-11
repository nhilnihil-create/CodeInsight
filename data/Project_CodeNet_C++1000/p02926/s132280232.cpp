#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define double long double
int main() {
	int n;
	cin>>n;
	vector<pair<double, pair<int, int>>>v;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		double val=atan2(x, y);
		if(val<0){
			val+=2*M_PI;
		}
		v.pb({val, {x, y}});
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>>vals;
	for(auto u:v){
		vals.pb({u.s.f, u.s.s});
	}
	for(auto u:v){
		vals.pb({u.s.f, u.s.s});
	}
	double ans=0;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j+i-1<2*n; j++){
			double xx=0;
			double yy=0;
			for(int k=j; k<=j+i-1; k++){
				xx+=vals[k].f;
				yy+=vals[k].s;
			}
			ans=max(ans, sqrt(xx*xx+yy*yy));
		}
	}
	cout<<setprecision(20)<<ans;
	return 0;
}