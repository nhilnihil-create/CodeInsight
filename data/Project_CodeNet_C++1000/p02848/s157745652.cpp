#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	string s;
	// nyuryoku
	cin >> n >> s;
	int keep[s.size()];
	for(int i=0;i<s.size();i++){
		keep[i] = s[i] - 'A' + n;
		keep[i] = keep[i] % 26;
		printf("%c",'A' + keep[i]);
	}
	// keisan

	// syutsuryoku
}