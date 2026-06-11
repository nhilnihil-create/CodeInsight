#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	string s;
	cin >> s;
	if(s=="SUN"){
		cout << 7 << endl;
	}
	else if(s=="SAT"){
		cout << 1 << endl;
	}
	else if(s[0]=='M'){
		cout << 6 << endl;
	}
	else if(s=="THU"){
		cout << 3 << endl;
	}
	else if(s[0]=='T'){
		cout << 5 << endl;
	}
	else if(s[0]=='W'){
		cout << 4 << endl;
	}
	else{
		cout << 2 << endl;
	}
}
