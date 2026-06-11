#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAXN = 200005;
using lint = long long;

int n, a[MAXN], b[MAXN];
queue<int> que;

int opable(int x){
	int l = (x + n - 1) % n;
	int r = (x + 1) % n;
	return max(0, b[x] - a[x]) / (b[l] + b[r]);
}

void solve(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) scanf("%d",&b[i]);
	for(int i=0; i<n; i++){
		if(opable(i)) que.push(i);
	}
	lint ans = 0;
	while(sz(que)){
		auto x = que.front(); que.pop();
		int l = (x + n - 1) % n, r = (x + 1) % n;
		ans += opable(x);
		b[x] -= (b[l] + b[r]) * opable(x);
		if(opable(l)) que.push(l);
		if(opable(r)) que.push(r);
	}
	for(int i=0; i<n; i++){
		if(a[i] != b[i]){
			puts("-1");
			return;
		}
	}
	cout << ans << endl;
}

int main(){
	solve();
}
