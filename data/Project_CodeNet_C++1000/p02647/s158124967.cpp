#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int imos[200005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	rep(_,k){
		bool change = false;
		memset(imos, 0, sizeof(imos));
		rep(i,n){
			int l = max(i-a[i], 0);
			int r = min(i+a[i], n-1);
			imos[l]++;
			imos[r+1]--;
		}
		rep(i,n){
			imos[i+1] += imos[i];
			if(a[i] != imos[i]) change = true;
			a[i] = imos[i];
		}
		if(!change) break;
	}
	rep(i,n) cout << a[i] << " ";
	cout << endl;
	return 0;
}
