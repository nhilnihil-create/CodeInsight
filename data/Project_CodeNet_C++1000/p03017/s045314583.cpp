#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, a, b, c, d;
string s;

int main(void){
	cin >> n >> a >> b >> c >> d >> s;
	a--;
	b--;
	c--;
	d--;
	s+='.';
	if(c > d){
		bool f = false;
		for(int i = b; i <= d; i++){
			if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') f = true;
		}
		if(!f){
			cout << "No" << endl;
			return 0;
		}
	}
	bool ans = true;
	for(int i = a; i < c; i++){
		if(s[i] == '#' && s[i+1] == '#') ans = false;
	}
	for(int i = b; i < d; i++){
		if(s[i] == '#' && s[i+1] == '#') ans = false;
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
