# include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, way[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	vector < int > g;
	for(int i = 0; i <= n; i++){
		if(s[i] == '0')g.push_back(i);
	}
	for(int i = 1, j = 0; i <= n; i++){
		if(s[i] == '1')continue;
		while(j < g.size() && g[j] < i - m)j++;
		if(j == g.size() || g[j] >= i){
			cout << "-1\n";
			return 0;
		}
		way[i] = g[j];
	}
	vector < int > inds;
	for(int i = n; i >= 1; i = way[i]){
		inds.push_back(i);
	}inds.push_back(0);
	reverse(inds.begin(), inds.end());
	for(int i = 1; i < inds.size(); i++){
		cout << inds[i] - inds[i - 1] << ' ';
	}
}