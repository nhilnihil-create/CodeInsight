#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;
map<string,bool>ada;

int main() {
	cin >> n;
	while(n--){
		cin >> s;
		if(ada[s]!=1)ans++;
		ada[s]=1;
	}
	cout << ans << '\n';
}
//avrs,0r