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
int copy(int const x){
	return x;
}

int main(){
	int n;cin>>n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) {
			int x;cin>>x;x--;a[i].pb(x);
		}
		a[i].pb(-1);
	}
	vector<int> now(n);
	vector<int> cnt(n,0);
	vector<bool> used(n,false);
	queue<int> q;
	for(int i = 0; i < n; i++) {
		now[i] = a[i][0]; 
		q.push(i);
	}
	int i = 0;
	int ans = 0;
	while(i <= n * (n - 1) / 2){
		i++;
		bool flag = true;
		int q_size = q.size();
		int j = 0;
		while(j < q_size) {
			int top = q.front();
			q.pop();
			if (now[top] != -1 && now[now[top]] == top && used[now[top]] == false && used[top] == false){//やりたい同士のとき
				int tmp = copy(now[top]);
				cnt[top]++;
				cnt[tmp]++;
				now[top] = a[top][cnt[top]];
				now[tmp] = a[tmp][cnt[tmp]];
				used[top] = true;
				used[tmp] =true;
				q.push(top);
				q.push(tmp);
				// for(int i = 0; i < n; i++) {
				// 	cout << now[top] << endl;
				// }
			}
			j++;
		}
		for(int i = 0; i < n; i++) {
				used[i] = false;
				}
			for(int i = 0; i < n; i++) {
				if (now[i] != -1){
					flag = false;
				}
			}
			ans++;
			if (flag){
				cout << ans << endl;
				return 0;
			}
		
	}
	
	for(int i = 0; i < n; i++) {
		if (now[i] != -1){
			cout << -1 << endl;
			return 0;
		}
	}
	return 0;
}