#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> a(n-1);
	vector<vector<pair<int,int>>> g(n); // {node,edge}
	REP(i,n-1){
		cin >> a[i].first >> a[i].second;
		a[i].first--; a[i].second--;
		
		g[a[i].first].push_back(make_pair(a[i].second, i));
		g[a[i].second].push_back(make_pair(a[i].first, i));
	}
	
	int maxsize = 0;
	int index=-1;
	REP(i,n){
		if(maxsize < (int)g[i].size()){
			maxsize = g[i].size();
			index = i;
		}
	}
	
	vector<int> color(n-1,0);
	queue<pair<int,int>> que;
	que.push(make_pair(index,0));
	while(!que.empty()){
		int now = que.front().first;
		int parcolor = que.front().second;
		que.pop();
		int col = 1;
		for(auto x: g[now]){
			int child = x.first;
			int edge = x.second;
			if(color[edge]!=0) continue;
			if(col!=parcolor){
				color[edge] = col;
				col++;
			}else{
				col++;
				color[edge] = col;
				col++;
			}
			que.push(make_pair(child, color[edge]));
		}
	}
	
	cout << maxsize << endl;
	REP(i,n-1){
		cout << color[i] << endl;
	}
	
	
	
	return 0;
}