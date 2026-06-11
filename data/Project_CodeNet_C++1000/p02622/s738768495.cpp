#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	for(int i = 0; i < min(s.size(), t.size()); i++){
		if(s[i] != t[i]) cnt++; 
	}
	cout << cnt << endl;
}


