#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
string solve() {
	int n; cin >> n;
	string s,y="Yes",no="No";
	cin >> s;
	if(n&1) {
		return no;
	}
	string ans="",res="";
	for(int i = 0;i<n/2;++i) res+=s[i];
	for(int i=n/2;i<n;++i) ans +=s[i];
 
	return (ans==res ? y: no);
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
 
	cout << solve() << "\n";
 
	return 0;
} 