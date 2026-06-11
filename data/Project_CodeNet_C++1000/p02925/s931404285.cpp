#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

struct edge { int to; int cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-10;
const double PI = acos(-1.0);
 
const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int main() {
	int n;
	cin >> n;
	queue<int> que[n+10];
	rep(i,n) rep(j,n-1) {
		int a; cin >> a;
		que[i+1].push(a);
	}

	int cnt = 0,ok = 0;
	queue<int> pre;
	rep(i,n) pre.push(i+1);
	while(1){
		int flag = 0,flags[n+10] = {};
		queue<int> tmp;
		while(pre.size()){
			int i = pre.front(); pre.pop();
			if(flags[i]) continue;
			flags[i] = 1;
			if(!que[i].empty()){
				int j = que[i].front();
				if(flags[j]) continue;
				if(!que[j].empty()){
					if(i == que[j].front()){
						que[i].pop();
						que[j].pop();
						tmp.push(i),tmp.push(j);
						//cout << cnt << " " <<  i << " " << j << endl;
						flag = 1;
						flags[j] = 1;
					}
				}
			}
		}
		pre = tmp;
		cnt++;

		// no-judge
		if(!flag) break;
		// ok-judge
		int fin = 1;
		for(int i = 1; i <= n; i++) if(!que[i].empty()) fin = 0;
		if(fin){
			ok = 1;
			break;
		}
	}
	cout << (ok ? cnt : -1) << endl;
	return 0;
}