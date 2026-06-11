#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
	int n,ans=0;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	rep(i,n){
		rep(j,i){
			rep(k,j){
				if (a[k] != a[j] && a[i] != a[j] && a[k] + a[j] > a[i]) ans++;
			}
		}
	}
	cout << ans<<endl;
}