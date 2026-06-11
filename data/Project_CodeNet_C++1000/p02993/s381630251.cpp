#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	for(ll i=1;i<4;i++){
		if(s[i-1]==s[i]){
			cout << "Bad";
			return 0;
		}
	}
	cout << "Good";
	// your code goes here
	return 0;
}