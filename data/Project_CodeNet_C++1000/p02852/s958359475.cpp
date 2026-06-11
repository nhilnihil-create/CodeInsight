# include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, way[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	set < int > st;
	st.insert(0); 
	for(int i = 1; i <= n; i++){
		if(s[i] == '1')continue;
		if(st.lower_bound(i - m) == st.end()){
			cout << "-1\n";
			return 0; 
		}
		way[i] = *st.lower_bound(i - m);
		st.insert(i);
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