#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;


void bfs(v2& a, v2& b){
	queue<int> q;
	q.push(a[0][0]);
	while(!q.empty()){
		int x = q.front()-1;
		int t = b[x][1];
		q.pop();
		rep(i, a[x][1]){
			int y = a[x][2+i]-1;
			if(a[y][0] != -1 && a[y][0] != -2){
				b[y][1] = t+1;
				a[y][0] = -1;
			}
			if(a[y][0] != -2) q.push(y+1);
		}
		a[x][0] = -2;
	}
}

int main(){
	int n;
	cin >> n;
	v2 a(n, v1(0));
	v2 b(n, v1(2, 0));
	rep(i, n){
		int m;
		cin >>m;
		a[i].push_back(m);
		b[i][0] = m;
		int x;
		cin >> x;
		a.at(i).push_back(x);
		rep(j, x){
			int y;
			cin >> y;
			a.at(i).push_back(y);
		}
	}
	bfs(a, b);
	for(int i = 1;i<n; i++){
		if(b[i][1] == 0) b[i][1] = -1;
	}
	rep(i, n){
		rep(j, 2){
			cout << b[i][j];
			if(j != 1) cout << " ";
			else cout << endl;
		}
	}
}

