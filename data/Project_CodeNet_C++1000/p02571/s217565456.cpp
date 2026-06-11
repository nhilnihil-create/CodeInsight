// timusg
#include <iostream>
#include <bits/stdc++.h>

int main(){
	using namespace std;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int mod = 1e9 + 7;
	int cas = 1;
	//cin >> cas;
	while(cas--){
		string s, t;
		cin >> s >> t;
		int res = t.size();
		for(int i=0; i<=s.size()-t.size(); ++i){
			int cur = 0;
			for(int j=0; j<t.size(); ++j){
				if(t[j]!=s[j+i]) cur++;
			}
			res =  min(res, cur);
		}

		cout << res << "\n";
	}
	
	return 0;
}  

