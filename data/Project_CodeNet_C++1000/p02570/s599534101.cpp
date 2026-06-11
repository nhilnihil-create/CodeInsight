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
		int64_t d, t ,s;

		cin >> d >> t >> s;

		if(t*s >= d){
			cout << "Yes\n";
		}

		else cout << "No\n";
	}
	
	return 0;
}  

