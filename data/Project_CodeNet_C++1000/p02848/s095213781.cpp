#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 

int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'A'+n;
		if(now>=26){
			now-=26;
		}
		cout << char(now+'A');
	}
	// your code goes here
	return 0;
}