#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	// nyuryoku
	cin >> s;
	map<char,int> mp;
	// keisan
	for(int i=0;i<4;i++){
		mp[s[i]]++;
	}
	// syutsuryoku
	int ok = 1;
	for(auto x:mp){
		if(x.second != 2){
			ok = 0;
		}
	}
	if(ok){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}