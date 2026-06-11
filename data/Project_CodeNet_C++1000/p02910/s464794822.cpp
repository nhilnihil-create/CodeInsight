#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	bool ans=true;
	for(ll i=0;i<s.size();i++){
		if((i+1)%2!=0){
			if(s[i]=='L'){
			ans=false;
			}
		}
		else{
			if(s[i]=='R'){
				ans=false;
			}
		}
	}
	if(ans){
		cout <<"Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}