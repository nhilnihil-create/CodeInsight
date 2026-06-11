#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MAXn = 1e5+8;
int vis[MAXn], h[MAXn];
vector<int> a[MAXn];
queue<int> q;
int ans = 0;
int n, m;

void bfs(){
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				int tmp = q.front();
				q.pop();
				bool isPeak = true;
				for(auto w : a[tmp]){
					if(h[w] >= h[tmp]) {
						isPeak = false;
					}
					if(!vis[w]){
						q.push(w);
						vis[w] = 1;
					}
				}
				if(isPeak){
				ans++;
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> h[i];
	}
	int u,v;
	for(int i = 1; i<=m;i++){
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	bfs();
	cout << ans;
	return 0;
} 