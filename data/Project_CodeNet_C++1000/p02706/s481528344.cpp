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

int n, m;
int main() {
	cin >> n >> m;
	rep(i, 0, m){
		int t; cin >> t;
		n -= t;
	}
	cout << max(-1, n) << endl;
	return 0;
}
