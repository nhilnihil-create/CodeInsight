#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	bool ok = true;
	rep(i,n){
		if(i%2 == 0 && s[i] == 'L') ok = false; 
		if(i%2 == 1 && s[i] == 'R') ok = false; 
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}