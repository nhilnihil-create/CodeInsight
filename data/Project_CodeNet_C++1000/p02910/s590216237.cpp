#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	ll ch=true;
	for(ll i=1;i<=s.size();i++){
		if(i%2==0){
			if(s[i-1]=='R'){
				ch=false;
			}
		}
		else{
			if(s[i-1]=='L'){
				ch=false;
			}
		}
	}
	cout << (ch?"Yes":"No");
	// your code goes here
	return 0;
}