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
int copy(int x){
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
	for(int i = 0; i < n; i++) {
		now[i] = a[i][0]; 
	}
	int i = 0;
	int ans = 0;
	while(i <= n * (n - 1) / 2){
		i++;
		bool flag = true;
		for(int i = 0; i < n; i++) {
			
			if (now[i] != -1 && now[now[i]] == i && used[now[i]] == false && used[i] == false){//やりたい同士のとき
				int tmp = copy(now[i]);
				cnt[i]++;
				cnt[tmp]++;
				now[i] = a[i][cnt[i]];
				now[tmp] = a[tmp][cnt[tmp]];
				used[i] = true;
				used[tmp] =true;
				// for(int i = 0; i < n; i++) {
				// 	cout << now[i] << endl;
				// }
			}
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