#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int n,m;cin>>n>>m;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	vector<bool> b(n,true);
	for(int i = 0; i < m; i++) {
		int x,y;cin>>x>>y;
		if (a[x-1] >= a[y-1]){
			b[y-1] = false;
		}
		if (a[x-1] <= a[y-1]){
			b[x-1] = false;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += b[i];
	}
	cout << ans << endl;
	return 0;
}