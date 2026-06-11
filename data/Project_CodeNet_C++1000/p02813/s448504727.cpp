#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	rep(i,n) cin >> p[i];
	rep(i,n) cin >> q[i];
	vector<int> a(n);
	rep(i,n){
		a[i] = i+1;
	}
	int counts = 1;
	map<vector<int>, int> cnt;
	do{
		cnt[a] = counts;
		counts++;
	}while(next_permutation(a.begin(),a.end()));
	int ans = abs(cnt[p] - cnt[q]);
	cout << ans << endl;
}