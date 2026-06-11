#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	string s,t,u;
	// nyuryoku
	cin >> n >> s >> t;
	u = s[0];
	u = u + t[0];
	// keisan
	for(int i=1;i<n;i++){
		u = u + s[i] + t[i];
	}
	cout << u;
	// syutsuryoku
}