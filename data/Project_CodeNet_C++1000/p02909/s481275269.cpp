#include "bits/stdc++.h"
using namespace std;

int main(){
	////freopen("input.txt","r",stdin);
//	///freopen("output.txt","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  
	string s;
	cin >> s;
	if (s=="Sunny"){
		cout << "Cloudy" << endl;
		return 0;
	}
	else if (s=="Rainy"){
		cout << "Sunny" << endl;
		return 0;
	}
	else if (s=="Cloudy"){
		cout << "Rainy" << endl;
		return 0;
	}
	}