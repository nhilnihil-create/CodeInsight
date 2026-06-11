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

int n;
int main() {
	cin >> n;
    vector<int> a(n);
	rep(_, 0, n-1){
		int t; cin >> t;
		t--;
		a[t]++;
	}
	rep(i, 0, n){
		cout << a[i] << endl;
	}
	return 0;
}
