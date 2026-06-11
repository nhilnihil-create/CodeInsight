#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s,t;
	cin>>s>>t;
	ll a,b;
	cin>>a>>b;
	string u;
	cin>>u;
	if(s==u){
		a--;
	}
	else{
		b--;
	}
	cout << a<<" "<<b;
	// your code goes here
	return 0;
}