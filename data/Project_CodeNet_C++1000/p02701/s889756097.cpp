#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set<string> var;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		var.insert(s);
	}
	cout << var.size();
	return 0;
}