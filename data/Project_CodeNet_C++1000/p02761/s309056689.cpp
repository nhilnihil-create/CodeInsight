#include <bits/stdc++.h>
using namespace std;

int ctoi(char c){
	switch(c){
	    case '0': return 0;
	    case '1': return 1;
	    case '2': return 2;
	    case '3': return 3;
	    case '4': return 4;
	    case '5': return 5;
	    case '6': return 6;
	    case '7': return 7;
	    case '8': return 8;
	    case '9': return 9;
	    default : return -1;
	 }
}

int main() {
	int n, m;
	cin >> n >> m;
	int s[m], c[m];
	for(int i = 0; i < m; i++) cin >> s[i] >> c[i];
	for(int i = 0; i < 1000; i++){
		string ans = to_string(i);
		if(ans.size() == n){
		bool check = true;
			for(int j = 0; j < m; j++){
				if(ctoi(ans[s[j] - 1]) != c[j]) check = false;
			}
			if(check){
				cout << ans << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
