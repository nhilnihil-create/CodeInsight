#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
using namespace std;

int n, k;
int main() {
	cin >> n >> k;
	vector<bool> have(n);
	rep(i,0,k){
		int d; cin >> d;
		rep(i,0,d){
			int t; cin >> t;
			have[t-1] = true;
		}
	}
		
	int ans = n;
	rep(i,0,n){
		if(have[i]) ans--;
	}
	cout << ans << endl;
	
	return 0;
}