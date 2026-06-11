#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	bool ans=false;
	for(ll i=1;i<s.size();i++){
		if(s[i-1]==s[i]){
			ans=true;
		}
	}
	cout << (ans?"Bad":"Good");
	// your code goes here
	return 0;
}