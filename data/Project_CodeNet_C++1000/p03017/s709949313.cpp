#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	a--;b--;c--;d--;
	string s; cin >> s;
	if(d>c){
		bool ok = true;
		for (int i = b; i <= d-1; ++i) {
			if(s[i] == '#' && s[i+1] == '#') ok = false;
		}
		for (int i = a; i <= c-1; ++i) {
			if(s[i] == '#' && s[i+1] == '#') ok = false;
		}
		if(ok) {
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}else{
		bool ok = true;
		bool flag = false;
		for (int i = b-1; i <= d-1; ++i) {
			if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') flag = true;
		}
		for (int i = a; i <= c-1; ++i) {
			if(s[i] == '#' && s[i+1] == '#') ok = false;
		}
		if(ok == true && flag == true){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}

