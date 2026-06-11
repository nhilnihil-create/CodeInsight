#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	// nyuryoku
	cin >> s;
	int n = s.size();
	// keisan
	if(n%2 != 0){
		cout << "No";
		return 0;
	}else{
		for(int i=0;i<n;i=i+2){
			if(s[i] != 'h' || s[i+1] != 'i'){
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
		return 0;
	}
	// syutsuryoku
}