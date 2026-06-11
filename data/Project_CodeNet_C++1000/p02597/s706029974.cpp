#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	int n;
	string s;
	cin >> n >> s;
	queue<int> pos;
	for(int i = 0; i < n; i++){
		if(s[i]=='W'){
			pos.push(i);
		}
	}
	int res = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i]=='W') continue;
		if(pos.empty()){
			break;
		}
		int ind = pos.front();
		pos.pop();
		if(ind > i) break;
		else{
			swap(s[ind],s[i]);
			++res;
		}
	}
	cout << res << "\n";
	return 0;
}
