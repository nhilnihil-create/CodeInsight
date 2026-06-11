#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	string s,t;
	cin >> s >> t;
	
	for(int i=0;i<s.length();i++){
		if(s[i]!=t[i]){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
