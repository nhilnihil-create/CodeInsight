#include <bits/stdc++.h>
using namespace std;

void solve(){
	string str;
	cin >> str;
	if(str[2] == str[3] && str[4] == str[5]){
		cout << "Yes" << "\n";
	}
	else{
		cout << "No" << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();	
}