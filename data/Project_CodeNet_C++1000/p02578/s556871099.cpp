#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
	ll n,ans = 0;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	for(int i = 1;i<n;i++){
		if (a[i] < a[i - 1]){
			ans+=a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << ans << endl;
}