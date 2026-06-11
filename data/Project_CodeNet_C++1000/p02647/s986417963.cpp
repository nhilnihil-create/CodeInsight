//すぬけさんAC
//https://www.youtube.com/watch?v=Kjk26wgMSQ8&feature=youtu.be

#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(ki,k){
		vector<int> b(n+1);
		rep(i,n){
			int l = max(0,i-a[i]);
			int r = min(i+a[i]+1,n);
			b[l]++;b[r]--;
		}
		rep(i,n) b[i+1] += b[i];
		b.pop_back();
		if(a==b) break;
		a = b;
	}
	rep(i,n) cout << a[i] << endl;
	return 0;
}

