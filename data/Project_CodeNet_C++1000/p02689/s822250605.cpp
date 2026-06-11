#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b;
	int h[100010];
	vector<int > v[100010];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(v[i].empty()){
			cnt++;
		}else{
			int flag = 1;
			for(auto x:v[i]){
				if(h[x] >= h[i]){
					flag = 0;
					break;
				}
			}
			if(flag)
				cnt++;
		}
	}
	cout << cnt << endl;
}
