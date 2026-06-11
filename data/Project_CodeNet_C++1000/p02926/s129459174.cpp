#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 102
#define M 30
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pld pair <ld, ld>

vector < pld > pts;

bool comp(pld x, pld y){
	return (atan2(x.ss, x.ff) < atan2(y.ss, y.ff));
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int i, j, b, n; cin>>n;
	ld x, y, ans = 0, xsum, ysum;
	for(i=0; i<n; i++){
		cin>>x>>y;
		if(x != 0 || y != 0){
			pts.pb({x, y});
		}
	}
	n = pts.size();
	if(n){
		sort(pts.begin(), pts.end(), comp);
		for(i=0; i<n; i++){
			xsum = 0; ysum = 0;
			for(j=0; j<n; j++){
				xsum = xsum + pts[(i+j)%n].ff;
				ysum = ysum + pts[(i+j)%n].ss;
				ans = max(ans, xsum*xsum + ysum*ysum);
			}
		}	
	}
	ans = sqrt(ans);
	cout<<setprecision(40)<<fixed<<ans;
	return 0;
}