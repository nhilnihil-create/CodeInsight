/* author   : mpily :-()
title : Competing.cpp
time :Sat May 30 13:38:34 2020

*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
	string T;
	cin >> T;
	int n = int(T.size());
	for(int i = 0; i < n; ++i){
		if(T[i] == '?'){
			T[i] = 'D';
		}
	}
	cout << T;
}
int main(){
	int t;
	t = 1;
	while(t--){
		solve();
		cout << "\n";
	}
	return 0;
}	