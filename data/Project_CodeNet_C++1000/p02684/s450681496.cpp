#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll k;


int main(){
	cin >> n >> k;
	vector<int> a(n+1);
	vector<int> mp(n+1);
	vector<int>mp1(n+1);
	vector<int> vis(n+1, 0);
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	int cur = 1;
	int h = 0;
	int cnt= 0;
	while(vis[cur] == 0){
		vis[cur] = 1;
		cnt++;
		mp1[cnt] = cur;
		cur = a[cur];
		h++;
	}
	fill(vis.begin(), vis.end(), 0);
	cnt = 0;
	while(vis[cur] == 0){
		vis[cur] = 1;
		cnt++;
		mp[cnt] = cur;
		cur = a[cur];
	}
	mp[0] = mp[cnt];
	int ans = k+1>h ? mp[(k - h + 1) % cnt] : mp1[k+1];
	cout << ans;
	
	return 0;
} 