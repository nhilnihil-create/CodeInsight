#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0), ios::sync_with_stdio(false);
	int n; cin >> n;
	const int MAX = 1e6+1;
	int cnt[MAX] = {};
	vi a(n);
	set<int> st;
	rep(i,n){
		cin >> a[i];
		if(st.count(a[i])){
			cnt[a[i]]++;
			continue;
		}
		st.insert(a[i]);
		for(int j = a[i]; j <= MAX; j += a[i]){
			cnt[j]++;
		}
	}
	int ans = 0;
	rep(i,n) if(cnt[a[i]] == 1) ans++;
	cout << ans;
	cout << "\n";
	return 0;
}
