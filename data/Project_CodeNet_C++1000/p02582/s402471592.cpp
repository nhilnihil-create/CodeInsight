#include <bits/stdc++.h>
using namespace std;

void solve(){
	string str;
	cin >> str;
	int rain = 0;
	int flag = 0;
	for(int i = 0; i < 3; i++){
		if(str[i] == 'R'){
			flag++;
		}
		else{
			flag = 0;
		}
		rain = max(rain, flag);
	}
	cout << rain << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();	
}