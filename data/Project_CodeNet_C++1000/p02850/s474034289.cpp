#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[100010],b[100010],c[100010],k = 0;
	vector<int> G[100010];
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		cin >> a[i] >> b[i]; a[i]--;b[i]--;
		G[a[i]].push_back(i);
		G[b[i]].push_back(i);
		c[i] = -1;
	}
	for(int i = 0;i < n;i++) chmax(k,(int)G[i].size());
	for(int i = 0;i < n;i++){
		set<int> st;
		int cnt = 0;
		for(int e : G[i]){
			if(c[e] != -1){
				st.insert(c[e]);
			}
		}
		for(int e : G[i]){
			if(c[e] == -1){
				while(st.count(cnt)) cnt++;
				st.insert(cnt);
				c[e] = cnt++;
			}
		}
	}
	cout << k << endl;
	for(int i = 0;i < n - 1;i++) cout << c[i] + 1 << endl;
}
