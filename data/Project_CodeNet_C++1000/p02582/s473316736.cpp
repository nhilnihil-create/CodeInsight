#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int ans=1, a=0;
	cin >> s;
	for(int i=0; i<3; i++){
		if(s[i]=='R'){
			a=1;
			if(s[i]==s[i+1]) ans++;
		}
	}
	if(ans==1 && a==0){
		cout << 0;
	}else{
		cout << ans;
	}
	return 0;
}

