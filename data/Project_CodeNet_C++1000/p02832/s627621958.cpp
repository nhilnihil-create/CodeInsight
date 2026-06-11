#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int INF=1e10;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int next=1,ans=0;
	rep(i,n){
		if(next==a[i]){
			next++;
		}else ans++;
	}
	if (ans == n)ans=-1;
	cout << ans << endl;
}