/* author   : mpily :-()
title : Competing.cpp
time :Tue May 12 09:52:55 2020
🤣️
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>ed;
vector<int>col;
vector<pair<int,int>>con; 
int ans = 0;
void dfs(int pos, int prevc){
	int c = 1 ;
	for(int x : ed[pos]){
		if(c == prevc)
			c++;
		if(!col[x-1]){
			col[x-1] = c;
			ans = max(ans,c);
			int nxt = con[x-1].first^con[x-1].second;
			nxt^=pos;
			dfs(nxt,c);
			c++;
		}
	}

}
int main(){
	cin >> n;
	ed.resize(n);
	col.resize(n-1);
	con.resize(n-1);
	for(int i = 0; i < n-1; ++i){
		int a,b;
		cin >> a >> b;
		a--;b--;
		ed[a].push_back(i+1);
		ed[b].push_back(i+1);
		con[i].first = a;
		con[i].second = b;
	}
	dfs(0,-1);
	cout << ans <<"\n";
	for(int x : col){
		cout << x <<"\n";
	}
	return 0;
}