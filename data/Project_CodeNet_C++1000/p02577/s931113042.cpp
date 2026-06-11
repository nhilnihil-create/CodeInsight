#include "bits/stdc++.h"
using namespace std;

using ll = long long;

signed main(){
	string s;
	cin >> s;

	ll sum = 0;
	for(int i=0;i < s.size();i++){
		sum = sum + (s[i]-'0');
	}

	if(sum % 9 == 0){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}

	return 0;
}